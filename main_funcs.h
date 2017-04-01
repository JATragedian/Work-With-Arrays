#ifndef MAIN_FUNCS_H
#define MAIN_FUNCS_H

#include <random>
#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

void helloMenu();
int helloMes();
void core();
void visualCreatingArray(int row, int column);
void firstMainMenu(int **firstArray, int **secondArray, int rows, int columns);
int firstMainMes();
void secondMainMenu(int **firstArray, int **secondArray, int rows, int columns);
int secondMainMes();
void fullArray(int **arr, int row, int column);
void showArray(int **arr, int row, int column);
void showArray(int **arr, int row, int column, int **arr2);
void sortArray(int **arr, int row, int column);
void showMinArray(int **arr, int row, int column);
void showMaxArray(int **arr, int row, int column);
void arithMeanArray(int **arr, int row, int column);
void loading(int t);
void slowShow(char *message);
void copyArray(int **toArr, int **fromArr, int row, int column);
int exMenu();

#endif