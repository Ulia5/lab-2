#define _CRT_SECURE_NO_WARNINGS
#include "Performance.h"

void Performance::setPerformance() 
{   // ������� ���������� ���������� � ����������
	cout << "\t\t�������� ����������: ";
	cin >> namePerf;
	while (namePerf.empty()) {		// ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> namePerf;
	};
	cout << "\t\t����� ���������� (� �������): ";
	cin >> performanceTime;
	cin.get();
	while (performanceTime < 0) {	// ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performanceTime;
		cin.get();
	}
	cout << "\t\t��� ��������: ";
	cin >> ageRestrictions;
	cin.get();
	while (ageRestrictions < 1740 || ageRestrictions > 2021) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> ageRestrictions;
		cin.get();
	}
}

void Performance::setPerformance(string name, int time, int age) 
{	// ������� ���������� ���������� � ����������(��� �����)
	namePerf = name;
	performanceTime = time;
	ageRestrictions = age;
}

void Performance::toString() 
{   // ����� ���������� � ����������
	if (!namePerf.empty()) {
		cout << "���������� � ����������:" << endl;
		cout << "\t\t������������ ����������: ";
		cout << namePerf << endl;
		cout << "\t\t����� ���������� (� �������): ";
		cout << performanceTime << endl;
		cout << "\t\t��� ��������: ";
		cout << ageRestrictions << endl;
		cout << "\t\t������� � ����������: ";
		cout << numberOfActors << endl;
		cout << "\t\t���������� ������������� ������ � ����������: ";
		cout << numberOfStageDirectors << endl;
	}
	else
		cout << "���������� ��������� ���������!" << endl;
}

string Performance::getNamePerf() 
{	// ����������� �������� ����������
	return namePerf;
}

void Performance::addActor() 
{	// ���������� ���-�� �������
	numberOfActors++;
}

void Performance::delActor() 
{	// ���������� ���-�� �������
	numberOfActors--;
}

void Performance::addStageDirector() 
{	// ���������� ���-�� ����������
	numberOfStageDirectors++;
}

void Performance::delStageDirector() 
{	// ���������� ���-�� ����������
	numberOfStageDirectors--;
}

void Performance::somePerf()
{	// ��������� ��������� ����������
	srand(1);
	namePerf = "�����-�� ���������� �" + to_string(1 + rand() % 50);
	srand(100);
	performanceTime = rand() % 400 + 1;
	srand(1740);
	ageRestrictions = rand() % 2021 + 1;
}