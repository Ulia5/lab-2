#pragma once
#include <malloc.h>
#include <iostream>
#include <string>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class StageDirector {		// ���������� ��������� �������� ������������� ������
	string nameDir;			// ���
	string surnameDir;		// �������
	int ageDir = 0;			// �������
	int numProjects = 0;	// ����������
	Theatre* jobPlace;		// ����� ������ 
	Performance performanceDir[50]; // ����������, ���������� ��� ������� ������� ��������� ������������� ������
public:
	void setStageDirector(Theatre* jobPlaceNew);
	void setStageDirector(string name, char* surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceDir(Performance* performance);
	void delPerformanceDir(Performance* performance);
};