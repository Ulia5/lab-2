/*#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct performance {         // Описание структуры Постановка
	char* namePerf = {};     // Название постановки
	int perfomanceTime = 0;  // Время постановки (в минутах)
	int ageRestrictions = 0; // Год премьеры
	int numberOfActors = 0;  // Количество актеров в постановке
	int numberOfStageDirectors = 0;  // Количество работников постановочной группы в постановке
};

performance setPerformance();
performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions);
void printPerformance(performance performance);
void changePerformanceTime(performance* performance);
void changeAgeRestrictions(performance* performance);*/