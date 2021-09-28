#pragma once
#include <malloc.h>
#include <iostream>
#include "Theatre.h"
#include "Performance.h"
using namespace std;

struct stageDirector {     // ���������� ��������� �������� ������������� ������
	char* nameDir = {};    // ���
	char* surnameDir = {}; // �������
	int ageDir = 0;        // �������
	int numProjects = 0;   // ����������
	theatre jobPlace = {}; // ����� ������ 
	performance performanceDir[50] = {}; // ����������, ���������� ��� ������� ������� ��������� ������������� ������
};

stageDirector setStageDirector(theatre* jobPlace);
stageDirector setStageDirector(char* nameDir, char* surnameDir, int ageDir, theatre* jobPlace);
void printStageDirector(stageDirector stageDirector);
void addPerformanceDir(stageDirector* stageDirector, performance* performance);
void delPerformanceDir(stageDirector* stageDirector, performance* performance);