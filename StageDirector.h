#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class StageDirector {     // Объявление структуры Работник постановочной группы
	char* nameDir;    // Имя
	char* surnameDir; // Фамилия
	int ageDir = 0;        // Возраст
	int numProjects = 0;   // Количество
	Theatre* jobPlace; // Место работы 
	Performance performanceDir[50]; // Постановки, созданнные при участии данного Работника постановочной группы
public:
	void setStageDirector(Theatre* jobPlaceNew);
	void setStageDirector(char* name, char* surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceDir(Performance* performance);
	void delPerformanceDir(Performance* performance);
};