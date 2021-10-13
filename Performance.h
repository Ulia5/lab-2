#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Performance {         // Описание структуры Постановка
	char* namePerf;     // Название постановки
	int perfomanceTime = 0;  // Время постановки (в минутах)
	int ageRestrictions = 0; // Год премьеры
	int numberOfActors = 0;  // Количество актеров в постановке
	int numberOfStageDirectors = 0;  // Количество работников постановочной группы в постановке
public:
	void setPerformance();
	void setPerformance(char* namePerf, int performanceTime, int ageRestrictions);
	void toString();
	char* getNamePerf();
	void addActor();
	void addStageDirector();
	void delActor();
	void delStageDirector();
};