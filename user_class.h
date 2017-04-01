#ifndef USER_CLASS_H
#define USER_CLASS_H

#include "user_struct.h"
#include <fstream>

class user {
public:
	user();
	void create();
	bool signMeIn();

private:
	UserInfo *users_;
	size_t nUser_;

} users;

//////////////////////////////////////////////////////////////////

user::user() // Need to write 0 in NumUsers file if it's a first time running;
{
	std::ifstream findUserNumber("NumUsers.txt");

	nUser_ = findUserNumber.get();

	findUserNumber.close();

	users_ = new UserInfo[];
}

void user::create() // No checks for going out of borders for now; 
{
	std::ofstream addLogin("Logins.txt", std::ios_base::app);
	std::ofstream addPassword("Passwords.txt", std::ios_base::app);
	std::ofstream incUsers("NumUsers.txt", std::ios_base::out | std::ios_base::trunc);

	char firstPas[40];

	do {
		system("cls");

		slowShow("//////////////////// Create a new account! ////////////////////");
		std::cout << std::endl << std::endl;

		slowShow(" Enter login: ");
		std::cin >> users_[nUser_].login;

		slowShow(" Enter password: ");
		std::cin >> firstPas;
		slowShow(" Repeat the password: ");
		std::cin >> users_[nUser_].password;

		if (strcmp(firstPas, users_[nUser_].password)) {
			slowShow("\n Passwords do not match! Please, try again...");
			system("pause >> NULL");
		}

	} while (strcmp(firstPas, users_[nUser_].password));

	addLogin << users_[nUser_].login << '\n';
	addPassword << users_[nUser_].password << '\n';

	loading(92);

	slowShow("\n\n Done! Your account number is: ");
	std::cout << nUser_;
	nUser_++;

	incUsers << nUser_;

	addLogin.close();
	addPassword.close();
	incUsers.close();

	system("pause >> NULL");

	system("cls");
}

bool user::signMeIn()
{
	char log[40];
	char pas[40];
	char buffLogin[40];
	char buffPassword[40];
	size_t uNum;
	bool found = false;
	bool correct = false;
	std::ifstream findLogin("Logins.txt");
	std::ifstream findPassword("Passwords.txt");
	

	do {

		do {

			system("cls");

			slowShow("//////////////////// Okay. Enter your login, so we can find you :) ////////////////////");
			std::cout << std::endl << std::endl;

			slowShow(" Login: ");
			std::cin >> log;
			std::cout << std::endl;

			if (!strcmp(log, "exit")) {
				return false;
			}

			slowShow(" Searching:");

			for (size_t i = 0; i < 10; i++) {
				std::cout << " *";
				Sleep(184);
			}

			std::cout << std::endl << std::endl;

			for (size_t i = 0; i < nUser_; i++) {
				findLogin >> users_[i].login;
				findPassword >> users_[i].password;
			}

			for (size_t i = 0; i < nUser_; i++) {
				if (!strcmp(log, users_[i].login)) {
					found = true;
					uNum = i;
					break;
				}
			}

			if (!found) {
				slowShow(" We didn't found you, sorry :(\n You can try again or type <<exit>> to quite to main menu.");
				system("pause >> NULL");
			}

		} while (!found);

		slowShow(" Password: ");
		std::cin >> pas;
		std::cout << std::endl;

		if (!strcmp(pas, users_[uNum].password)) {
			slowShow(" /// Correct! Welcome,");
			slowShow(users_[uNum].login);
			slowShow(";) ///");
			correct = true;
		}

		else {
			slowShow(" Incorrect password! Try again.");
			system("pause >> NULL");
		}

	} while (!correct);

	system("pause >> NULL");

	return true;
}

#endif