#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Stage.h"
using namespace std;

class Theatre {                         // Описание класса Театр
	int numberOfStages = 0;             // Количество сцен
	Stage stages[5];                    // Сцены
	int numberOfActors = 0;           // Количество актеров
	int numberOfStageDirectors = 0;     // Количество работников постановочной группы
	char* nameTh;                       // Название театра
	int yearOfFoundation = 0;           // Год основания
public:
	void setTheatre();
	void setTheatre(char* name, int year, int countStages, Stage** masStages);
	void toString();
	void addStage();
	void addStage(char name[50], int capacity, int countPerf, Performance* performances[]);
	void delStage(int numStage);
	void addActor();
	char* getNameTh();
	Stage* getStages(int number);
};
