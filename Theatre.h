#pragma once
#include <malloc.h>
#include <iostream>
#include "Stage.h"
//#include "Actor.h"
//#include "StageDirector.h"
using namespace std;

struct theatre {                             // Описание структуры Театр
	char* nameTh = {};                       // Название театра
	int yearOfFoundation = 0;                // Год основания
	int numberOfStages = 0;                  // Количество сцен
	stage stages[5] = {};                  // Сцены
	/*actor actors[50] = {};                   // Актеры
	stageDirector stageDirectors[50] = {};*/ // Работники постановочной группы
	int numberOfActors = 0;                  // Количество актеров
	int numberOfStageDirectors = 0;          // Количество работников постановочной группы
};

theatre setTheatre();
theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, stage stages[],
	int numberOfActors, /*actor actors[],*/ int numberOfStageDirectors/*, stageDirector stageDirectors[50]*/);
void printTheatre(theatre theatre);
void addStage(theatre *theatre);
void delStage(theatre *theatre, int numStage);
/*void addActor(theatre *theatre);
void delActor(theatre *theatre, int numActor);
void addStageDirector(theatre *theatre);
void delStageDirector(theatre *theatre, int numStageDirector);*/
