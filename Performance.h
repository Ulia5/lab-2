#pragma once
#include <malloc.h>
#include <stdio.h>
#include <iostream>
/*#include "Actor.h"
#include "StageDirector.h"*/
using namespace std;

struct performance {         // �������� ��������� ����������
	char* namePerf = {};     // �������� ����������
	int perfomanceTime = 0;  // ����� ���������� (� �������)
	int ageRestrictions = 0; // ��� ��������
	int numberOfActors = 0;  // ���������� ������� � ����������
	/*actor actors[50] = {};*/   // ������ ����������� � ����������
	int numberOfStageDirectors = 0;  // ���������� ���������� ������������� ������ � ����������
	/*stageDirector stageDirectors[25] = {};*/ // ��������� ������������� ������ � ����������
};

performance setPerformance();
performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions
	, int numberOfActors/*, actor actors[50]*/, int numberOfStageDirectors/*, stageDirector stageDirectors[25]*/);
void printPerformance(performance performance);
void addActor(performance* performance);
void delActor(performance* performance, int numActors);
/*void addStageDirector(stage* stage);
void delStageDirector(stage* stage, int numStageDirector);*/