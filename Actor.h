#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

struct actor {             // ���������� ��������� �����
	char* nameAct = {};    // ��� ������
	char* surnameAct = {}; // ������� ������
	int ageAct = 0;        // ������� ������
	int roles = 0;         // ���������� �����
	theatre jobPlace = {}; // ����� ������
	performance performanceAct[50] = {}; // ���������� � �������� ������� ������
};

actor setActor(theatre* jobPlace);
actor setActor(char* nameAct, char* surnameAct, int ageAct, theatre* jobPlace);
void printActor(actor actor);
void addPerformanceAct(actor* actor, performance* performance);
void delPerformanceAct(actor* actor, performance* performance);