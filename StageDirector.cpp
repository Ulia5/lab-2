#include "StageDirector.h"

stageDirector setStageDirector(theatre* jobPlace) { // ������� ���������� ���������� � ��������� ������������� ������
	stageDirector stageDirector = {};
	stageDirector.nameDir = (char*)malloc(50);
	stageDirector.surnameDir = (char*)malloc(50);
	cout << "\t��� ��������� ������������� ������: ";
	gets_s(stageDirector.nameDir, 50);
	cout << "\t������� ��������� ������������� ������: ";
	gets_s(stageDirector.surnameDir, 50);
	cout << "\t������� ��������� ������������� ������: ";
	cin >> stageDirector.ageDir;
	cin.get();
	stageDirector.jobPlace = *jobPlace;
	jobPlace->numberOfStageDirectors++;
	return stageDirector;
}

stageDirector setStageDirector(char* nameDir, char* surnameDir, int ageDir, theatre* jobPlace) {
	// ������� ���������� ���������� � ��������� ������������� ������(��� �����)
	stageDirector stageDirector = {};
	stageDirector.nameDir = nameDir;
	stageDirector.surnameDir = surnameDir;
	stageDirector.ageDir = ageDir;
	stageDirector.jobPlace = *jobPlace;
	jobPlace->numberOfStageDirectors++;
	return stageDirector;
}

void printStageDirector(stageDirector stageDirector) { // ����� ���������� � ��������� ������������� ������
	if (stageDirector.nameDir != NULL) {
		cout << "���������� � ��������� ������������� ������:" << endl;
		cout << "��� � �������: ";
		cout << stageDirector.nameDir << ' ' << stageDirector.surnameDir << endl;
		cout << "�������: ";
		cout << stageDirector.ageDir << endl;
		cout << "����� ������: ";
		cout << stageDirector.jobPlace.nameTh << endl;
		cout << "���������� �����: ";
		cout << stageDirector.numProjects << endl;
		if (stageDirector.numProjects > 0) {
			cout << "����� ���������� ���: " << endl;
			for (int i = 0; i < stageDirector.numProjects; i++)
				cout << i + 1 << ") " << stageDirector.performanceDir[i].namePerf << endl;
		}
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void addPerformanceDir(stageDirector* stageDirector, performance* performance) { // ���������� ���������� � ������ �����
	stageDirector->performanceDir[stageDirector->numProjects] = *performance;
	stageDirector->numProjects++;
	performance->numberOfStageDirectors++;
}

void delPerformanceDir(stageDirector* stageDirector, performance* performance) { // �������� ���������� �� ������ �����
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < stageDirector->numProjects; i++)
		if (stageDirector->performanceDir[i].namePerf == performance->namePerf) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < stageDirector->numProjects - 1; i++) {
			stageDirector->performanceDir[i] = stageDirector->performanceDir[i + 1];
		}
		stageDirector->performanceDir[stageDirector->numProjects - 1] = {};
		stageDirector->numProjects--;
		performance->numberOfStageDirectors--;
	}
	else
		cout << "����� ���������� �� �������!" << endl;
}