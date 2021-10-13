#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Performance.h"
using namespace std;

class Stage {                     // Объявление класса Сцена
	char nameSt[100];            // Название сцены
	int hallCapacity = 0;         // Вместимость зала
	int numberOfPerformances = 0; // Количество постановок
	Performance* performances[50]; // Список постановок
public:
	void setStage();
	void setStage(char* name, int capacity, int countPerf, Performance* performances[]);
	void toString();
	void addPerformance();
	void addPerformance(char* namePerf, int performanceTime, int ageRestrictions);
	void delPerformance(int numPerformance);
	int getNumberOfPerformances();
	Performance* getPerformance(int number);
};