#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Theatre.h"
#include "Actor.h"
/*#include "StageDirector.h"*/
#include <locale>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Theatre* theatres = new Theatre[3]; // Создаем объекты типа Театра
	Stage* stages[2]; // Создаем объекты типа Сцена
	Performance* performances[2]; // Создаем объекты типа Постановка
	Performance* performances0[1];
	Actor actors[2]; // Создаем объекты типа Актер
	for (int i = 0; i < 2; i++) {
		stages[i] = new Stage;
	}
	for (int i = 0; i < 2; i++) {
		performances[i] = new Performance;
	}
	for (int i = 0; i < 1; i++) {
		performances0[i] = new Performance;
	}
	actors[0].setActor((char*)"Иван", (char*)"Иванов", 32, &theatres[0]);
	actors[1].setActor((char*)"Петр", (char*)"Петров", 32, &theatres[0]);
	performances[0]->setPerformance((char*)"Игра", 200, 2020);
	performances[1]->setPerformance((char*)"Мир", 220, 2000);
	performances0[0]->setPerformance((char*)"Лира", 120, 2021);
	stages[0]->setStage((char*)"Большая сцена", 500, 2, performances);
	stages[1]->setStage((char*)"Малая сцена", 100, 1, performances0);
	theatres[0].setTheatre((char*)"Музыкальный театр", 1990, 2, stages);
	theatres[0].toString();
	actors[0].addPerformanceAct(performances0[0]);
	actors[0].addPerformanceAct(performances[0]);
	theatres[0].toString();
	actors[0].toString();
	actors[0].delPerformanceAct(performances0[0]);
	theatres[0].toString();
	actors[0].toString();
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
