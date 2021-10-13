#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include "Stage.h"
using namespace std;

class Theatre {                         // �������� ������ �����
	int numberOfStages = 0;             // ���������� ����
	Stage stages[5];                    // �����
	int numberOfActors = 0;           // ���������� �������
	int numberOfStageDirectors = 0;     // ���������� ���������� ������������� ������
	char* nameTh;                       // �������� ������
	int yearOfFoundation = 0;           // ��� ���������
public:
	void setTheatre();
	void setTheatre(char* name, int year, int countStages, Stage** masStages);
	void toString();
	void addStage();
	void addStage(char name[50], int capacity, int countPerf, Performance* performances[]);
	void delStage(int numStage);
	void addActor();
	char* getNameTh();
	Stage* getStages(int number);
};
