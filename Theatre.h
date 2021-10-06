#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
//#include "Stage.h"
using namespace std;

class Theatre {                              // Описание класса Театр
	/*int numberOfStages = 0;                  // Количество сцен
	stage stages[5] = {};                    // Сцены
	int numberOfActors = 0;                  // Количество актеров
	int numberOfStageDirectors = 0;          // Количество работников постановочной группы*/
	char* nameTh = {};                       // Название театра
	int yearOfFoundation = 0;                // Год основания
public:
	void setTheatre();
	void setTheatre(char*, int/*, int numberOfStages, stage stages[]*/);
	void toString();
	//void addStage(theatre* theatre);
	//void delStage(theatre* theatre, int numStage);
};
