#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Theatre.h"
#include "Actor.h"
#include "StageDirector.h"
#include <locale>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	theatre musicalTheatre; // Создаем объекты типа Театра
	theatre dramTheatre;
	actor Ivanov, Petrov; // Создаем объекты типа Актер
	stageDirector Sidorov, Orlov; // Создаем объекты типа Работник постановочной группы
	musicalTheatre = setTheatre();
	cout << "\n";
	stage bigStage[1]; // Создаем объект типа Сцена
	performance romeoAndJuliet[1]; // Создаем объект типа Постановка
	romeoAndJuliet[0] = setPerformance((char*)"Ромео и Джульета", 180, 2007);
	bigStage[0] = setStage((char*)"Средняя", 300, 1, romeoAndJuliet);
	dramTheatre = setTheatre((char*)"Драматический театр", 1999, 1, bigStage);
	Ivanov = setActor(&musicalTheatre);
	Petrov = setActor((char*)"Петр", (char*)"Петров", 27, &dramTheatre);
	Sidorov = setStageDirector(&musicalTheatre);
	Orlov = setStageDirector((char*)"Олег", (char*)"Орлов", 25, &dramTheatre);
	printActor(Ivanov);
	addPerformanceAct(&Ivanov, &musicalTheatre.stages[0].performances[0]);
	printActor(Ivanov);
	printActor(Petrov);
	addPerformanceAct(&Petrov, &dramTheatre.stages[0].performances[0]);
	printActor(Petrov);
	printStageDirector(Orlov);
	addPerformanceDir(&Orlov, &dramTheatre.stages[0].performances[0]);
	printStageDirector(Orlov);
	printTheatre(musicalTheatre);
	cout << "\n";
	printTheatre(dramTheatre);
	cout << "\n";
	delPerformanceAct(&Petrov, &dramTheatre.stages[0].performances[0]);
	delPerformanceDir(&Orlov, &dramTheatre.stages[0].performances[0]);
	printTheatre(dramTheatre);
	cout << "\n";
	addStage(&musicalTheatre);
	addPerformance(&musicalTheatre.stages[0]);
	printTheatre(musicalTheatre);
	delPerformance(&musicalTheatre.stages[0], 1);
	printTheatre(musicalTheatre);
	cout << "\n";
	delStage(&musicalTheatre, 0); 
	printTheatre(musicalTheatre);
}
