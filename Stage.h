#pragma once
#include <malloc.h>
#include <iostream>
#include "Performance.h"
using namespace std;

struct stage {        // ќбъ€вление структуры —цена
	char* nameSt = {};
	int hallCapacity = 0;
	int numberOfPerformances = 0;
	//performance performances[50];
};

stage setStage();
stage setStage(char* nameSt, int hallCapacity, int numberOfPerformances/*, performance performances[]*/);
void printStage(stage stage);
/*void addPerformance(stage *stage);*/
/*void delPerformance(stage *stage, int numPerformance);*/