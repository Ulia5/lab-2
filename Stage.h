#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Performance.h"
using namespace std;

class Stage {                     // ���������� ������ �����
	char nameSt[100];            // �������� �����
	int hallCapacity = 0;         // ����������� ����
	int numberOfPerformances = 0; // ���������� ����������
	Performance* performances[50]; // ������ ����������
public:
	void setStage();
	void setStage(char* name, int capacity, int countPerf, Performance* performances[]);
	void toString();
	void addPerformance();
	void addPerformance(char* namePerf, int performanceTime, int ageRestrictions);
	void delPerformance(int numPerformance);
	int getNumberOfPerformances();
	Performance* getPerformance(int number);
};