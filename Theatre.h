#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Stage.h"
using namespace std;

struct theatre {                             // Описание структуры Театр
	char* nameTh = {};                       // Название театра
	int yearOfFoundation = 0;                // Год основания
	int numberOfStages = 0;                  // Количество сцен
	stage stages[5] = {};                    // Сцены
	int numberOfActors = 0;                  // Количество актеров
	int numberOfStageDirectors = 0;          // Количество работников постановочной группы
};

theatre setTheatre();
theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, stage stages[]);
void printTheatre(theatre theatre);
void addStage(theatre *theatre);
void delStage(theatre *theatre, int numStage);
