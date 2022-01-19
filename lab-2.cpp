#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Theatre.h"
#include "Actor.h"
#include "StageDirector.h"
#include "Sword.h"
#include "Suit.h"
#include <locale>
#include <windows.h>

int allPerformances(Theatre th) 
{	// Нахождение общего кол-ва спектаклей в театре
	int num = 0;
	for (int i = 0; i < th.numberOfStages; i++)
		num += th.getStages(i)->getNumberOfPerformances();
	return num;
}

void ageEx(int age) {
	if (age < 18 || age > 100)
		throw exception("Wrong format!");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Объявление и инициализация объектов, используемых в примерах
	Theatre* theatres = new Theatre[2];
	Stage* stages[2]; 
	Performance* performances[2];
	Performance* performances0[1];
	Actor actors[3];
	StageDirector stageDirectors[2][1];
	for (int i = 0; i < 2; i++) {
		stages[i] = new Stage;
	}
	for (int i = 0; i < 2; i++) {
		performances[i] = new Performance;
	}
	for (int i = 0; i < 1; i++) {
		performances0[i] = new Performance;
	}
	// Заполнение информации об объектах, используемых в примерах
	actors[0].setActor((char*)"Иван", (char*)"Иванов", 32, &theatres[0]);
	actors[1].setActor((char*)"Петр", (char*)"Петров", 35, &theatres[0]);
	stageDirectors[0][0].setStageDirector((char*)"Игорь", (char*)"Иванов", 23, &theatres[0]);
	stageDirectors[1][0].setStageDirector((char*)"Павел", (char*)"Петров", 30, &theatres[0]);
	performances[0]->setPerformance("Игра", 200, 2020);
	performances[1]->setPerformance("Мир", 220, 2000);
	performances0[0]->setPerformance("Лира", 120, 2021);
	actors[0].addPerformanceAct(performances[0]);
	actors[0].addPerformanceAct(performances[1]);
	stages[0]->setStage((char*)"Большая сцена", 500, 2, performances);
	stages[1]->setStage((char*)"Малая сцена", 100, 1, performances0);
	theatres[0].setTheatre((char*)"Музыкальный театр", 1990, 2, stages);

	// Примеер для задания №1
	cout << "Задание №1\n" << endl;
	Suit newSuit = { "черный", 40, 5000, "фрак" };
	newSuit.printCostume();
	cout << "Задание №2\n" << endl;
	Sword newSword = { 5, 10, 10000 };
	newSword.printProps();
	newSword.changePeriodOfUse(2);
	newSword.printProps();
	newSword.changePeriodOfUse(9);
	newSword.printProps();
	cout << "Задание №3\n" << endl;
	cout << "Общая стоимость реквизита и костюмов: " << (newSuit.getPrice() + newSword.getPrice()) << endl;

	// Освобождение памяти
	delete[] theatres;
	for (int i = 0; i < 2; i++) {
		delete stages[i];
	}
	for (int i = 0; i < 2; i++) {
		delete performances[i];
	}
	for (int i = 0; i < 1; i++) {
		delete performances0[i];
	}
}
