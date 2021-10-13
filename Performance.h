#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Performance {         // �������� ��������� ����������
	char* namePerf;     // �������� ����������
	int perfomanceTime = 0;  // ����� ���������� (� �������)
	int ageRestrictions = 0; // ��� ��������
	int numberOfActors = 0;  // ���������� ������� � ����������
	int numberOfStageDirectors = 0;  // ���������� ���������� ������������� ������ � ����������
public:
	void setPerformance();
	void setPerformance(char* namePerf, int performanceTime, int ageRestrictions);
	void toString();
	char* getNamePerf();
	void addActor();
	void addStageDirector();
	void delActor();
	void delStageDirector();
};