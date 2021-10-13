#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

class StageDirector {     // ���������� ��������� �������� ������������� ������
	char* nameDir;    // ���
	char* surnameDir; // �������
	int ageDir = 0;        // �������
	int numProjects = 0;   // ����������
	Theatre* jobPlace; // ����� ������ 
	Performance performanceDir[50]; // ����������, ���������� ��� ������� ������� ��������� ������������� ������
public:
	void setStageDirector(Theatre* jobPlaceNew);
	void setStageDirector(char* name, char* surname, int age, Theatre* jobPlaceNew);
	void toString();
	void addPerformanceDir(Performance* performance);
	void delPerformanceDir(Performance* performance);
};