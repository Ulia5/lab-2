#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Performance {				// Описание структуры Постановка
	string namePerf;			// Название постановки
	int performanceTime = 0;	// Время постановки (в минутах)
	int ageRestrictions = 0;	// Год премьеры
	int numberOfActors = 0;		// Количество актеров в постановке
	int numberOfStageDirectors = 0;  // Количество работников постановочной группы в постановке
public:
	void setPerformance();
	void setPerformance(string namePerf, int performanceTime, int ageRestrictions);
	void toString();
	string getNamePerf();
	void addActor();
	void addStageDirector();
	void delActor();
	void delStageDirector();
	void somePerf();
};