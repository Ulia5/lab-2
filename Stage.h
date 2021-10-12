#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
//#include "Performance.h"
using namespace std;

class Stage {                     // Объявление класса Сцена
	char nameSt[100];            // Название сцены
	int hallCapacity = 0;         // Вместимость зала
	/*int numberOfPerformances = 0; // Количество постановок
	performance performances[50]; // Список постановок*/
public:
	void setStage();
	void setStage(char* name, int capacity/*, performance performances[]*/);
	void toString();
	/*void addPerformance();
	void delPerformance(int numPerformance);*/
};