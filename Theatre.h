#pragma once
#include <malloc.h>
#include <iostream>
#include "Stage.h"
//#include "Actor.h"
//#include "StageDirector.h"
using namespace std;

struct theatre {                             // �������� ��������� �����
	char* nameTh = {};                       // �������� ������
	int yearOfFoundation = 0;                // ��� ���������
	int numberOfStages = 0;                  // ���������� ����
	stage stages[5] = {};                  // �����
	/*actor actors[50] = {};                   // ������
	stageDirector stageDirectors[50] = {};*/ // ��������� ������������� ������
	int numberOfActors = 0;                  // ���������� �������
	int numberOfStageDirectors = 0;          // ���������� ���������� ������������� ������
};

theatre setTheatre();
theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, stage stages[],
	int numberOfActors, /*actor actors[],*/ int numberOfStageDirectors/*, stageDirector stageDirectors[50]*/);
void printTheatre(theatre theatre);
void addStage(theatre *theatre);
void delStage(theatre *theatre, int numStage);
/*void addActor(theatre *theatre);
void delActor(theatre *theatre, int numActor);
void addStageDirector(theatre *theatre);
void delStageDirector(theatre *theatre, int numStageDirector);*/
