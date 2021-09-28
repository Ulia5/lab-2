#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Performance.h"
using namespace std;

struct stage {        // Объявление структуры Сцена
	char* nameSt = {}; // Название сцены
	int hallCapacity = 0; // Вместимость зала
	int numberOfPerformances = 0; // Количество постановок
	performance performances[50]; // Список постановок
};

stage setStage();
stage setStage(char* nameSt, int hallCapacity, int numberOfPerformances, performance performances[]);
void printStage(stage stage);
void addPerformance(stage *stage);
void delPerformance(stage *stage, int numPerformance);