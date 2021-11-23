#pragma once
#include <malloc.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class Actor {				// Объявление структуры Актер
	string nameAct;			// Имя актера
	string surnameAct;		// Фамилия актера
	int ageAct = 0;			// Возраст актера
	int roles = 0;			// Количество ролей
	Theatre* jobPlace;		// Место работы
	Performance performanceAct[50]; // Постановки с участием данного актера
public:
	void setActor(Theatre* jobPlace);
	void setActor(string name, string surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceAct(Performance* performance);
	void delPerformanceAct(Performance* performance);
	int& age_change();
	Actor operator+ (Actor act);
	Actor operator++ ();
	Actor operator++ (int notused);
};