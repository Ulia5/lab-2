#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Theatre.h"
#include "Stage.h"
#include <locale>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	theatre musicalTheatre; // Создаем объекты типа Театра
	theatre dramTheatre;
	musicalTheatre = setTheatre();
	cout << "\n";
	stage bigStage[1];
	bigStage[0] = setStage((char*)"Средняя", 300, 20);
	dramTheatre = setTheatre((char*)"Драматический театр", 1999, 1, bigStage, 32, 21);
	printTheatre(musicalTheatre);
	cout << "\n";
	printTheatre(dramTheatre);
	cout << "\n";
	addStage(&musicalTheatre);
	printTheatre(musicalTheatre);
	cout << "\n";
	delStage(&musicalTheatre, 0); // Номера от 0
	printTheatre(musicalTheatre);
}