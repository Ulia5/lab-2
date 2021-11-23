#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Stage.h"
using namespace std;

class Theatre {                         // Описание класса Театр
	int numberOfStages = 0;             // Количество сцен
	Stage stages[5];                    // Сцены
	int numberOfActors = 0;				// Количество актеров
	int numberOfStageDirectors = 0;     // Количество работников постановочной группы
	static int allActors;				// Общее кол-во актеров во всех театрах
	static int allStageDirectors;		// Общее кол-во работников во всех театрах
	string nameTh;                      // Название театра
	int yearOfFoundation = 0;           // Год основания
public:
	void setTheatre();
	void setTheatre(string name, int year, int countStages, Stage** masStages);
	void toString();
	void addStage();
	void addStage(string name, int capacity, int countPerf, Performance* performances[]);
	void delStage(int numStage);
	void addActor();
	void addStageDirector();
	string getNameTh();
	Stage* getStages(int number);
	int getNumberOfActors();
	int getNumberOfStageDirectors();
	friend int allPerformances(Theatre th);
	static void countAllAct(Theatre th);
	static void countAllDir(Theatre th);
	static int getAllAct();
	static int getAllDir();
};
