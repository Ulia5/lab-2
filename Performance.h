#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
/*#include "Actor.h"
#include "StageDirector.h"*/
using namespace std;

struct performance {         // Описание структуры Постановка
	char* namePerf = {};     // Название постановки
	int perfomanceTime = 0;  // Время постановки (в минутах)
	int ageRestrictions = 0; // Год премьеры
	int numberOfActors = 0;  // Количество актеров в постановке
	/*actor actors[50] = {};*/   // Актеры участвующие в постановке
	int numberOfStageDirectors = 0;  // Количество работников постановочной группы в постановке
	/*stageDirector stageDirectors[25] = {};*/ // Работники постановочной группы в постановке
};

performance setPerformance();
performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions
	, int numberOfActors/*, actor actors[50]*/, int numberOfStageDirectors/*, stageDirector stageDirectors[25]*/);
void printPerformance(performance performance);
void addActor(performance* performance);
void delActor(performance* performance, int numActors);
/*void addStageDirector(stage* stage);
void delStageDirector(stage* stage, int numStageDirector);*/