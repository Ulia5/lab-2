#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Performance.h"
using namespace std;

class Stage {						// ���������� ������ �����
	string nameSt;					// �������� �����
	int hallCapacity = 0;			// ����������� ����
	int numberOfPerformances = 0;	// ���������� ����������
	Performance* performances[50];	// ������ ����������
public:
	void setStage();
	void setStage(string name, int capacity, int countPerf, Performance* performances[]);
	void toString();
	void addPerformance();
	void addPerformance(string namePerf, int performanceTime, int ageRestrictions);
	void delPerformance(int numPerformance);
	int getNumberOfPerformances();
	Performance* getPerformance(int number);
};