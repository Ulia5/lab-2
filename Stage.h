#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
//#include "Performance.h"
using namespace std;

class Stage {                     // ���������� ������ �����
	char nameSt[100];            // �������� �����
	int hallCapacity = 0;         // ����������� ����
	/*int numberOfPerformances = 0; // ���������� ����������
	performance performances[50]; // ������ ����������*/
public:
	void setStage();
	void setStage(char* name, int capacity/*, performance performances[]*/);
	void toString();
	/*void addPerformance();
	void delPerformance(int numPerformance);*/
};