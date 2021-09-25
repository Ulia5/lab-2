#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Stage.h"
using namespace std;

struct theatre {                             // �������� ��������� �����
	char* nameTh = {};                       // �������� ������
	int yearOfFoundation = 0;                // ��� ���������
	int numberOfStages = 0;                  // ���������� ����
	stage stages[5] = {};                    // �����
	int numberOfActors = 0;                  // ���������� �������
	int numberOfStageDirectors = 0;          // ���������� ���������� ������������� ������
};

theatre setTheatre();
theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, stage stages[]);
void printTheatre(theatre theatre);
void addStage(theatre *theatre);
void delStage(theatre *theatre, int numStage);
