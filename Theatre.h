#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
//#include "Stage.h"
using namespace std;

class Theatre {                              // �������� ������ �����
	/*int numberOfStages = 0;                  // ���������� ����
	stage stages[5] = {};                    // �����
	int numberOfActors = 0;                  // ���������� �������
	int numberOfStageDirectors = 0;          // ���������� ���������� ������������� ������*/
	char* nameTh = {};                       // �������� ������
	int yearOfFoundation = 0;                // ��� ���������
public:
	void setTheatre();
	void setTheatre(char*, int/*, int numberOfStages, stage stages[]*/);
	void toString();
	//void addStage(theatre* theatre);
	//void delStage(theatre* theatre, int numStage);
};
