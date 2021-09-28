#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

struct stageDirector {     // Объявление структуры Работник постановочной группы
	char* nameDir = {};    // Имя
	char* surnameDir = {}; // Фамилия
	int ageDir = 0;        // Возраст
	int numProjects = 0;   // Количество
	theatre jobPlace = {}; // Место работы 
	performance performanceDir[50] = {}; // Постановки, созданнные при участии данного Работника постановочной группы
};

stageDirector setStageDirector(theatre* jobPlace);
stageDirector setStageDirector(char* nameDir, char* surnameDir, int ageDir, theatre* jobPlace);
void printStageDirector(stageDirector stageDirector);
void addPerformanceDir(stageDirector* stageDirector, performance* performance);
void delPerformanceDir(stageDirector* stageDirector, performance* performance);