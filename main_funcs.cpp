#include "main_funcs.h"
#include "user_class.h"

void helloMenu()
{
	int answer;
	bool moveOn = false;

	while (!moveOn) {
		answer = helloMes();

		switch (answer) {

		case 0: moveOn = users.signMeIn();
			break;
		case 1: users.create();
			break;
		case 2: {
					int ans = exMenu();
					switch (ans) {
					case 0: exit(0);
						break;
					case 1:
						break;
					}

		}
			break;
		}
	}
}

int helloMes()
{
	system("cls");

	int key = 0;
	char welcome[] = "//////////////////// Welcome! Please, sign in or sign up if you don't have an account yet ;) ////////////////////";
	int code;

	slowShow(welcome);
	std::cout << std::endl << std::endl;

	slowShow(" Sign in");
	std::cout << std::endl << std::endl;

	slowShow(" Create a new account");
	std::cout << std::endl << std::endl;

	slowShow(" Exit");

	do {
		system("cls");

		std::cout << welcome;
		std::cout << std::endl << std::endl;

		key = (key + 3) % 3;

		if (key == 0) std::cout << " -> Sign in\n" << std::endl;
		else std::cout << " Sign in\n" << std::endl;
		if (key == 1) std::cout << " -> Create a new account\n" << std::endl;
		else std::cout << " Create a new account\n" << std::endl;
		if (key == 2) std::cout << " -> Exit\n" << std::endl;
		else std::cout << " Exit" << std::endl;
		code = _getch();

		if (code == 224) {
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}

	} while (code != 13);

	system("cls");
	return key;
}

void core()
{
	system("cls");

	slowShow("//////////////////// Set size of the array ////////////////////");
	std::cout << std::endl << std::endl;

	int **firstArray, **secondArray;
	size_t rows, columns;

	slowShow(" Set the number of rows in the array: ");
	std::cin >> rows;
	std::cout << std::endl;
	slowShow(" Now set the number of columns: ");
	std::cin >> columns;

	firstArray = new int*[rows];
	for (size_t i = 0; i < rows; i++) {
		firstArray[i] = new int[columns];
	}

	secondArray = new int*[rows];
	for (size_t i = 0; i < rows; i++) {
		secondArray[i] = new int[columns];
	}

	visualCreatingArray(rows, columns);

	firstMainMenu(firstArray, secondArray, rows, columns);

	secondMainMenu(firstArray, secondArray, rows, columns);


	for (size_t i = 0; i < rows; i++) {
		delete[]firstArray[i];
	}
	delete[]firstArray;


	for (size_t i = 0; i < rows; i++) {
		delete[]secondArray[i];
	}
	delete[]secondArray;
}

void visualCreatingArray(int row, int column)
{
	system("cls");

	std::cout << std::endl;
	slowShow(" Creating an array...");
	std::cout << std::endl << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << " #";
			Sleep(90);
			if (j == column - 1) {
				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl;

	slowShow(" \aPress any button to continue...");
	system("pause >> NULL");
}

void firstMainMenu(int **firstArray, int **secondArray, int rows, int columns)
{
	bool moveOn = false;

	while (!moveOn) {
		int answer = firstMainMes();

		switch (answer) {

		case 0: fullArray(firstArray, rows, columns);
			break;
		case 1: showArray(firstArray, rows, columns);
			break;
		case 2: sortArray(firstArray, rows, columns);
			break;
		case 3: showMinArray(firstArray, rows, columns);
			break;
		case 4: showMaxArray(firstArray, rows, columns);
			break;
		case 5: arithMeanArray(firstArray, rows, columns);
			break;
		case 6: {
					copyArray(secondArray, firstArray, rows, columns);
					moveOn = true;
		}
			break;
		case 7: {
					int ans = exMenu();
					switch (ans) {
					case 0: exit(0);
						break;
					case 1:
						break;
					}

		}
			break;
		}
	}
}

int firstMainMes()
{
	system("cls");

	int key = 0;
	int code;
	char choose[] = "//////////////////// Choose an option. ////////////////////";

	slowShow(choose);
	std::cout << std::endl << std::endl;

	slowShow(" Full the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show the array");
	std::cout << std::endl << std::endl;

	slowShow(" Sort the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show minimum value of the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show maximum value of the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show the arithmetic mean");
	std::cout << std::endl << std::endl;

	slowShow(" Copy the array");
	std::cout << std::endl << std::endl;

	slowShow(" Exit");
	std::cout << std::endl << std::endl;

	do {
		system("cls");

		key = (key + 8) % 8;

		std::cout << choose;
		std::cout << std::endl << std::endl;

		if (key == 0) std::cout << " -> Full the array\n" << std::endl;
		else  std::cout << " Full the array\n" << std::endl;
		if (key == 1) std::cout << " -> Show the array\n" << std::endl;
		else  std::cout << " Show the array\n" << std::endl;
		if (key == 2) std::cout << " -> Sort the array\n" << std::endl;
		else  std::cout << " Sort the array\n" << std::endl;
		if (key == 3) std::cout << " -> Show minimum value of the array\n" << std::endl;
		else  std::cout << " Show minimum value of the array\n" << std::endl;
		if (key == 4) std::cout << " -> Show maximum value of the array\n" << std::endl;
		else  std::cout << " Show maximum value of the array\n" << std::endl;
		if (key == 5) std::cout << " -> Show the arithmetic mean\n" << std::endl;
		else  std::cout << " Show the arithmetic mean\n" << std::endl;
		if (key == 6) std::cout << " -> Copy the array\n" << std::endl;
		else  std::cout << " Copy the array\n" << std::endl;
		if (key == 7) std::cout << " -> Exit\n" << std::endl;
		else  std::cout << " Exit\n" << std::endl;
		code = _getch();

		if (code == 224) {
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}

	} while (code != 13);

	return key;
}

void secondMainMenu(int **firstArray, int **secondArray, int rows, int columns)
{
	for (;;) {
		int answer = secondMainMes();

		switch (answer) {

		case 0: {
					int arrayNumber;

					do {
						system("cls");
						std::cout << std::endl;

						slowShow(" Enter the array number you wish to full (1 or 2): ");
						std::cin >> arrayNumber;

						if (arrayNumber == 1) fullArray(firstArray, rows, columns);
						else if (arrayNumber == 2) fullArray(secondArray, rows, columns);
						else {
							std::cout << std::endl << std::endl;
							slowShow(" 1 to 2 numbers only!");
							system("pause >> NULL");
						}
					} while (arrayNumber != 1 && arrayNumber != 2);
		}
			break;
		case 1: {
					int arrayNumber;

					do {
						system("cls");
						std::cout << std::endl;

						slowShow(" Enter the array number (1 or 2) or type 0 to see them both: ");
						std::cin >> arrayNumber;

						if (arrayNumber == 0) showArray(firstArray, rows, columns, secondArray);
						else if (arrayNumber == 1) showArray(firstArray, rows, columns);
						else if (arrayNumber == 2) showArray(secondArray, rows, columns);
						else {
							std::cout << std::endl << std::endl;
							slowShow(" 1 to 3 numbers only!");
							system("pause >> NULL");
						}
					} while (arrayNumber != 0 && arrayNumber != 1 && arrayNumber != 2);
		}
			break;
		case 2: {
					int arrayNumber;

					do {
						system("cls");
						std::cout << std::endl;

						slowShow(" Enter the array number (1 or 2): ");
						std::cin >> arrayNumber;

						if (arrayNumber == 1) sortArray(firstArray, rows, columns);
						else if (arrayNumber == 2) sortArray(secondArray, rows, columns);
						else {
							std::cout << std::endl << std::endl;
							slowShow(" Enter 1 or 2!");
							system("pause >> NULL");
						}
					} while (arrayNumber != 1 && arrayNumber != 2);
		}
			break;
		case 3: showMinArray(firstArray, rows, columns);
			break;
		case 4: showMaxArray(firstArray, rows, columns);
			break;
		case 5: arithMeanArray(firstArray, rows, columns);
			break;
		case 6: {
					int ans = exMenu();
					switch (ans) {
					case 0: exit(0);
						break;
					case 1:
						break;
					}

		}
			break;
		}
	}

}

int secondMainMes()
{
	system("cls");

	int key = 0;
	int code;
	char choose[] = "//////////////////// Choose an option. ////////////////////";

	slowShow(choose);
	std::cout << std::endl << std::endl;

	slowShow(" Full the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show the array");
	std::cout << std::endl << std::endl;

	slowShow(" Sort the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show minimum value of the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show maximum value of the array");
	std::cout << std::endl << std::endl;

	slowShow(" Show the arithmetic mean");
	std::cout << std::endl << std::endl;

	slowShow(" Exit");
	std::cout << std::endl << std::endl;

	do {
		system("cls");

		key = (key + 7) % 7;

		std::cout << choose;
		std::cout << std::endl << std::endl;

		if (key == 0) std::cout << " -> Full the array\n" << std::endl;
		else  std::cout << " Full the array\n" << std::endl;
		if (key == 1) std::cout << " -> Show the array\n" << std::endl;
		else  std::cout << " Show the array\n" << std::endl;
		if (key == 2) std::cout << " -> Sort the array\n" << std::endl;
		else  std::cout << " Sort the array\n" << std::endl;
		if (key == 3) std::cout << " -> Show minimum value of the array\n" << std::endl;
		else  std::cout << " Show minimum value of the array\n" << std::endl;
		if (key == 4) std::cout << " -> Show maximum value of the array\n" << std::endl;
		else  std::cout << " Show maximum value of the array\n" << std::endl;
		if (key == 5) std::cout << " -> Show the arithmetic mean\n" << std::endl;
		else  std::cout << " Show the arithmetic mean\n" << std::endl;
		if (key == 6) std::cout << " -> Exit\n" << std::endl;
		else  std::cout << " Exit\n" << std::endl;
		code = _getch();

		if (code == 224) {
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}

	} while (code != 13);

	return key;
}

void fullArray(int **arr, int row, int column)
{
	system("cls");

	int from, to;

	slowShow("//////////////////// Array filling ////////////////////");
	std::cout << std::endl << std::endl;

	slowShow(" Random numbers will be generated from: ");
	std::cin >> from;
	std::cout << std::endl;

	slowShow(" to: ");
	std::cin >> to;

	while (to < from) {
		std::cout << std::endl;
		slowShow(" Maximum possible random number should be greater then the minimum!");
		std::cout << std::endl;

		slowShow(" Please, reset the maximum possible random number: ");
		std::cin >> to;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(from, to);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = dist(gen);
		}
	}

	loading(150);

	std::cout << std::endl << std::endl << std::endl;

	slowShow(" \aThe array fulled seccefully!");
	system("pause >> NULL");
}

void showArray(int **arr, int row, int column)
{
	system("cls");

	slowShow("//////////////////// Array display ////////////////////");
	std::cout << std::endl << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << ' ' << arr[i][j];
			Sleep(10);
			if (j == column - 1) {
				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl;
	system("pause >> NULL");
}

void showArray(int **arr, int row, int column, int **arr2)
{
	system("cls");

	slowShow("//////////////////// Array display ////////////////////");
	std::cout << std::endl << std::endl;

	slowShow(" The first array: ");
	std::cout << std::endl << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << ' ' << arr[i][j];
			Sleep(10);
			if (j == column - 1) {
				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl << std::endl << std::endl;

	slowShow(" The second array: ");
	std::cout << std::endl << std::endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << ' ' << arr2[i][j];
			Sleep(10);
			if (j == column - 1) {
				std::cout << std::endl;
			}
		}
	}

	std::cout << std::endl;
	system("pause >> NULL");

}

void sortArray(int **arr, int row, int column)
{
	system("cls");

	for (int i = 0; i < row; i++) {
		for (int j = 1; j < column; j++) {
			for (int k = j; k > 0 && arr[i][k - 1] > arr[i][k]; k--) {
				std::swap(arr[i][k - 1], arr[i][k]);
			}
		}
	}

	for (int i = 0; i < column; i++) {
		for (int j = 1; j < row; j++) {
			for (int k = j; k > 0 && arr[k - 1][i] > arr[k][i]; k--) {
				std::swap(arr[k - 1][i], arr[k][i]);
			}
		}
	}

	std::cout << std::endl;
	slowShow(" Sorting: ");

	for (int i = 0; i < 10; i++) {
		std::cout << " *";
		Sleep(244);
	}

	std::cout << std::endl << std::endl;

	slowShow(" \aThe array has been successfully sorted!");
	system("pause >> NULL");
}

void showMinArray(int **arr, int row, int column)
{
	system("cls");

	int x = INT_MAX;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (arr[i][j] < x) {
				x = arr[i][j];
			}
		}
	}

	loading(167);

	std::cout << std::endl << std::endl;
	slowShow(" \aMinimal element is: ");
	std::cout << x;
	system("pause >> NULL");
}

void showMaxArray(int **arr, int row, int column)
{
	system("cls");

	int x = INT_MIN;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (arr[i][j] > x) {
				x = arr[i][j];
			}
		}
	}

	loading(167);

	std::cout << std::endl << std::endl;
	slowShow(" \aMaximal element is: ");
	std::cout << x;
	system("pause >> NULL");
}

void arithMeanArray(int **arr, int row, int column)
{
	system("cls");

	int x = 0;
	int k = row * column;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			x += arr[i][j];
		}
	}

	loading(345);

	std::cout << std::endl << std::endl;
	slowShow(" \aArithmetical mean is: ");
	std::cout << x / k;
	system("pause >> NULL");
}

void loading(int t)
{
	slowShow("\n Loading:");

	for (int i = 0; i < 10; i++) {
		std::cout << " *";
		Sleep(t);
	}
}

void slowShow(char *message)
{
	for (size_t i = 0; i <= strlen(message); i++) {
		std::cout << message[i];
		Sleep(10);
	}
}

void copyArray(int **toArr, int **fromArr, int row, int column)
{
	system("cls");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			toArr[i][j] = fromArr[i][j];
		}
	}

	std::cout << std::endl;

	slowShow(" Copying: ");

	for (int i = 0; i < 10; i++) {
		std::cout << " *";
		Sleep(238);
	}

	std::cout << std::endl << std::endl;

	slowShow(" \aThe contents of an array has been successfully copied in the second array!");
	std::cout << std::endl;

	slowShow(" More options are available in menu now!");
	system("pause >> NULL");
}

int exMenu()
{
	system("cls");

	int key = 0;
	int code;

	slowShow("//////////////////// Do you really wish to quit? ////////////////////");
	std::cout << std::endl << std::endl;

	slowShow(" Yes");
	std::cout << std::endl << std::endl;

	slowShow(" No");
	std::cout << std::endl << std::endl;

	do {
		system("cls");

		std::cout << "//////////////////// Do you really wish to quit? ////////////////////";
		std::cout << std::endl << std::endl;

		key = (key + 2) % 2;

		if (key == 0) std::cout << " -> Yes\n" << std::endl;
		else std::cout << " Yes\n" << std::endl;
		if (key == 1) std::cout << " -> No\n" << std::endl;
		else std::cout << " No\n" << std::endl;
		code = _getch();

		if (code == 224) {
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);

	system("cls");
	return key;
}