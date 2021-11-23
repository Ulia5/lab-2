#pragma once
#include <malloc.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Stage.h"
using namespace std;

class Theatre {                         // �������� ������ �����
	int numberOfStages = 0;             // ���������� ����
	Stage stages[5];                    // �����
	int numberOfActors = 0;				// ���������� �������
	int numberOfStageDirectors = 0;     // ���������� ���������� ������������� ������
	static int allActors;				// ����� ���-�� ������� �� ���� �������
	static int allStageDirectors;		// ����� ���-�� ���������� �� ���� �������
	string nameTh;                      // �������� ������
	int yearOfFoundation = 0;           // ��� ���������
public:
	void setTheatre();
	void setTheatre(string name, int year, int countStages, Stage** masStages);
	void toString();
	void addStage();
	void addStage(string name, int capacity, int countPerf, Performance* performances[]);
	void delStage(int numStage);
	void addActor();
	void addStageDirector();
	string getNameTh();
	Stage* getStages(int number);
	int getNumberOfActors();
	int getNumberOfStageDirectors();
	friend int allPerformances(Theatre th);
	static void countAllAct(Theatre th);
	static void countAllDir(Theatre th);
	static int getAllAct();
	static int getAllDir();
};
