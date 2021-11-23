#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Performance {				// �������� ��������� ����������
	string namePerf;			// �������� ����������
	int performanceTime = 0;	// ����� ���������� (� �������)
	int ageRestrictions = 0;	// ��� ��������
	int numberOfActors = 0;		// ���������� ������� � ����������
	int numberOfStageDirectors = 0;  // ���������� ���������� ������������� ������ � ����������
public:
	void setPerformance();
	void setPerformance(string namePerf, int performanceTime, int ageRestrictions);
	void toString();
	string getNamePerf();
	void addActor();
	void addStageDirector();
	void delActor();
	void delStageDirector();
	void somePerf();
};