#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Theatre.h"
/*#include "Actor.h"
#include "StageDirector.h"*/
#include <locale>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Theatre* theatres = new Theatre[3]; // Создаем объекты типа Театра
	Stage* stages[3];
	for (int i = 0; i < 3; i++) {
		stages[i] = new Stage;
	}
	stages[1]->setStage();
	stages[0]->setStage((char*)"Большая сцена", 500);
	stages[2]->setStage((char*)"Средняя сцена", 300);
	theatres[0].setTheatre();
	theatres[1].setTheatre((char*)"Драматический театр", 1999, 3, stages);
	theatres[0].toString();
	theatres[1].toString();
	theatres[0].addStage();
	theatres[0].addStage((char*)"Средняя сцена", 200);
	theatres[1].delStage(1);
	theatres[0].toString();
	theatres[1].toString();
	delete[] theatres;
	for (int i = 0; i < 2; i++) {
		delete stages[i];
	}
	/*actor Ivanov, Petrov; // Создаем объекты типа Актер
	stageDirector Sidorov, Orlov; // Создаем объекты типа Работник постановочной группы
	stage bigStage[1]; // Создаем объект типа Сцена
	performance romeoAndJuliet[1]; // Создаем объект типа Постановка
	romeoAndJuliet[0] = setPerformance((char*)"Ромео и Джульета", 180, 2007);
	bigStage[0] = setStage((char*)"Средняя", 300, 1, romeoAndJuliet);
	Ivanov = setActor(&musicalTheatre);
	Petrov = setActor((char*)"Петр", (char*)"Петров", 27, &dramTheatre);
	Sidorov = setStageDirector(&musicalTheatre);
	Orlov = setStageDirector((char*)"Олег", (char*)"Орлов", 25, &dramTheatre);*/
}
