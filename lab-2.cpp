#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Theatre.h"
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
	dramTheatre = setTheatre((char*)"Драматический театр", 1999, 2, 32, 21);
	printTheatre(musicalTheatre);
	printTheatre(dramTheatre);
	/*addStage(musicalTheatre);
	printTheatre(musicalTheatre);
	delStage(musicalTheatre, 0); // Номера от 0
	printTheatre(musicalTheatre);*/
}