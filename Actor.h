#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

struct actor {             // Объявление структуры Актер
	char* nameAct = {};    // Имя актера
	char* surnameAct = {}; // Фамилия актера
	int ageAct = 0;        // Возраст актера
	int roles = 0;         // Количество ролей
	theatre jobPlace = {}; // Место работы
	performance performanceAct[50] = {}; // Постановки с участием данного актера
};

actor setActor(theatre* jobPlace);
actor setActor(char* nameAct, char* surnameAct, int ageAct, theatre* jobPlace);
void printActor(actor actor);
void addPerformanceAct(actor* actor, performance* performance);
void delPerformanceAct(actor* actor, performance* performance);