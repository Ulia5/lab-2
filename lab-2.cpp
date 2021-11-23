#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Theatre.h"
#include "Actor.h"
#include "StageDirector.h"
#include <locale>
#include <windows.h>

int allPerformances(Theatre th) 
{	// Нахождение общего кол-ва спектаклей в театре
	int num = 0;
	for (int i = 0; i < th.numberOfStages; i++)
		num += th.getStages(i)->getNumberOfPerformances();
	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Объявление и инициализация объектов, используемых в примерах
	Theatre* theatres = new Theatre[3];
	Stage* stages[2]; 
	Performance* performances[2];
	Performance* performances0[1];
	Actor actors[3];
	StageDirector stageDirectors[2];
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
	actors[1].setActor((char*)"Петр", (char*)"Петров", 32, &theatres[0]);
	stageDirectors[0].setStageDirector((char*)"Игорь", (char*)"Иванов", 23, &theatres[0]);
	stageDirectors[1].setStageDirector((char*)"Павел", (char*)"Петров", 30, &theatres[0]);
	performances[0]->setPerformance("Игра", 200, 2020);
	performances[1]->setPerformance("Мир", 220, 2000);
	performances0[0]->setPerformance("Лира", 120, 2021);
	actors[0].addPerformanceAct(performances[0]);
	actors[0].addPerformanceAct(performances[1]);
	stages[0]->setStage((char*)"Большая сцена", 500, 2, performances);
	stages[1]->setStage((char*)"Малая сцена", 100, 1, performances0);
	theatres[0].setTheatre((char*)"Музыкальный театр", 1990, 2, stages);
	theatres[1].setTheatre((char*)"Драматический театр", 2000, 1, stages);
	actors[2].setActor((char*)"Михаил", (char*)"Боярский", 60, &theatres[1]);
	// Пример для задания
	cout << "Актеров в 1м театре: " << theatres[0].getNumberOfActors() << ", актеров во 2м театре: " << theatres[1].getNumberOfActors() << endl;
	cout << "\nЗначение общего количества актеров до обращения к методу: " << Theatre::getAllAct() << endl;
	Theatre::countAllAct(theatres[0]);
	Theatre::countAllAct(theatres[1]);
	cout << "\nЗначение общего количества актеров после обращения к методу: " << Theatre::getAllAct() << endl;
	cout << "\nРаботников в 1м театре: " << theatres[0].getNumberOfStageDirectors() << ", работников во 2м театре: " << theatres[1].getNumberOfStageDirectors() << endl;
	cout << "\nЗначение общего количества работников до обращения к методу: " << Theatre::getAllDir() << endl;
	Theatre::countAllDir(theatres[0]);
	Theatre::countAllDir(theatres[1]);
	cout << "\nЗначение общего количества актеров после обращения к методу: " << Theatre::getAllDir() << endl;
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
