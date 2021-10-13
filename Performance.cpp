#define _CRT_SECURE_NO_WARNINGS
#include "Performance.h"

void Performance::setPerformance() {                 // ������� ���������� ���������� � ����������
	namePerf = (char*)malloc(50);
	cout << "\t\t�������� ����������: ";
	gets_s(namePerf, 49);
	while (namePerf == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> namePerf;
		cin.get();
	};
	cout << "\t\t����� ���������� (� �������): ";
	cin >> perfomanceTime;
	cin.get();
	while (perfomanceTime < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> perfomanceTime;
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

void Performance::setPerformance(char* name, int time, int age) {  
	// ������� ���������� ���������� � ����������(��� �����)
	namePerf = new char[100];
	strcpy(namePerf, name);
	perfomanceTime = time;
	ageRestrictions = age;
}

void Performance::toString() { // ����� ���������� � ����������
	if (namePerf != NULL) {
		cout << "���������� � ����������:" << endl;
		cout << "\t\t������������ ����������: ";
		cout << namePerf << endl;
		cout << "\t\t����� ���������� (� �������): ";
		cout << perfomanceTime << endl;
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

char* Performance::getNamePerf() {
	return namePerf;
}

void Performance::addActor() {
	numberOfActors++;
}

void Performance::delActor() {
	numberOfActors--;
}

void Performance::addStageDirector() {
	numberOfStageDirectors++;
}

void Performance::delStageDirector() {
	numberOfStageDirectors--;
}