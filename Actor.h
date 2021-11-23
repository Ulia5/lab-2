#pragma once
#include <malloc.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class Actor {				// ���������� ��������� �����
	string nameAct;			// ��� ������
	string surnameAct;		// ������� ������
	int ageAct = 0;			// ������� ������
	int roles = 0;			// ���������� �����
	Theatre* jobPlace;		// ����� ������
	Performance performanceAct[50]; // ���������� � �������� ������� ������
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