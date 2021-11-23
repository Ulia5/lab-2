#include "StageDirector.h"
void StageDirector::setStageDirector(Theatre* jobPlaceNew) 
{	// ������� ���������� ���������� � ��������� ������������� ������
	cout << "\t��� ��������� ������������� ������: ";
	cin >> nameDir;
	cout << "\t������� ��������� ������������� ������: ";
	cin >> surnameDir;
	cout << "\t������� ��������� ������������� ������: ";
	cin >> ageDir;
	cin.get();
	jobPlace = jobPlaceNew;
	jobPlaceNew->addStageDirector();
}

void StageDirector::setStageDirector(string name, char* surname, int age, Theatre* jobPlaceNew) 
{	// ������� ���������� ���������� � ��������� ������������� ������(��� �����)
	nameDir = name;
	surnameDir = surname;
	ageDir = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addStageDirector();
}

void StageDirector::toString() 
{	// ����� ���������� � ��������� ������������� ������
	if (!nameDir.empty()) {
		cout << "���������� � ��������� ������������� ������:" << endl;
		cout << "��� � �������: ";
		cout << nameDir << ' ' << surnameDir << endl;
		cout << "�������: ";
		cout << ageDir << endl;
		cout << "����� ������: ";
		cout << jobPlace->getNameTh() << endl;
		cout << "���������� �����: ";
		cout << numProjects << endl;
		if (numProjects > 0) {
			cout << "����� ���������� ���: " << endl;
			for (int i = 0; i < numProjects; i++)
				cout << i + 1 << ") " << performanceDir[i].getNamePerf() << endl;
		}
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void StageDirector::addPerformanceDir(Performance* performance) 
{	// ���������� ���������� � ������ �����
	performanceDir[numProjects] = *performance;
	performanceDir[numProjects].addStageDirector();
	performance->addStageDirector();
	numProjects++;
}

void StageDirector::delPerformanceDir(Performance* performance) 
{	// �������� ���������� �� ������ �����
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < numProjects; i++)
		if (performanceDir[i].getNamePerf() == performance->getNamePerf()) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < numProjects - 1; i++) {
			performanceDir[i] = performanceDir[i + 1];
		}
		performanceDir[numProjects - 1] = {};
		numProjects--;
		performance->delStageDirector();
	}
	else
		cout << "����� ���������� �� �������!" << endl;
}