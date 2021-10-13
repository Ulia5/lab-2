#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class Actor {             // ���������� ��������� �����
	char* nameAct;    // ��� ������
	char* surnameAct; // ������� ������
	int ageAct = 0;        // ������� ������
	int roles = 0;         // ���������� �����
	Theatre* jobPlace; // ����� ������
	Performance performanceAct[50]; // ���������� � �������� ������� ������
public:
	void setActor(Theatre* jobPlace);
	void setActor(char* name, char* surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceAct(Performance* performance);
	void delPerformanceAct(Performance* performance);
};