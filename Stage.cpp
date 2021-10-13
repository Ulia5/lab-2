#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::setStage() {   // ������� ���������� ����� ���������
	cout << "\t�������� �����: ";
	gets_s(nameSt, 49);
	while (nameSt == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		gets_s(nameSt, 49);
	};
	cout << "\t����������� ����: ";
	cin >> hallCapacity;
	cin.get();
	while (hallCapacity < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> hallCapacity;
		cin.get();
	}
	cout << "\t���������� ����������: ";
	cin >> numberOfPerformances;
	cin.get();
	for (int i = 0; i < numberOfPerformances; i++)
			performances[i]->setPerformance();
}

void Stage::setStage(char name[50], int capacity, int countPerf, Performance* performancesNew[]) {
	strcpy(nameSt, name);
	hallCapacity = capacity;
	numberOfPerformances = countPerf;
	for (int i = 0; i < numberOfPerformances; i++)
		performances[i] = performancesNew[i];
}

void Stage::toString() { // ������� ������ ���������� � �����
	if (nameSt != NULL) {
		cout << "���������� � ����� ";
		cout << nameSt << ":" << endl;
		cout << "\t����������� ����: ";
		cout << hallCapacity << endl;
		cout << "\t���������� �� �����: ";
		cout << numberOfPerformances << endl;
		for (int i = 0; i < numberOfPerformances; i++) {
			cout << "\t���������� �" << i + 1 << ':' << endl;
			performances[i]->toString();
		}
	}
	else
		cout << "���������� ��������� ���������!" << endl;
}

void Stage::addPerformance() { // ���������� ����������
	performances[numberOfPerformances]->setPerformance();
	numberOfPerformances++;
}

void Stage::addPerformance(char* namePerf, int performanceTime, int ageRestrictions) { // ���������� ����������
	performances[numberOfPerformances]->setPerformance(namePerf, performanceTime, ageRestrictions);
	numberOfPerformances++;
}

void Stage::delPerformance(int numPerformance) {  // �������� ����������
	if (numPerformance >= 0 && numPerformance < numberOfPerformances) {
		for (int i = numPerformance; i < numberOfPerformances - 1; i++) {
			performances[i] = performances[i + 1];
		}
		performances[numberOfPerformances - 1] = {};
		numberOfPerformances--;
	}
	else
		cout << "����� ���������� ������ ���� � ���������� �� 0 �� " << numberOfPerformances - 1 << " (�������)." << endl;
}

int Stage::getNumberOfPerformances() {
	return numberOfPerformances;
}

Performance* Stage::getPerformance(int number) {
	return performances[number];
}