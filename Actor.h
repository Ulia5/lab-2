#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class Actor {             // Объявление структуры Актер
	char* nameAct;    // Имя актера
	char* surnameAct; // Фамилия актера
	int ageAct = 0;        // Возраст актера
	int roles = 0;         // Количество ролей
	Theatre* jobPlace; // Место работы
	Performance performanceAct[50]; // Постановки с участием данного актера
public:
	void setActor(Theatre* jobPlace);
	void setActor(char* name, char* surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceAct(Performance* performance);
	void delPerformanceAct(Performance* performance);
};