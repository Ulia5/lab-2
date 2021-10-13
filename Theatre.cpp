#define _CRT_SECURE_NO_WARNINGS
#include "Theatre.h"

void Theatre::setTheatre() {                      // ������� ���������� ���������� � ������
	nameTh = new char[100];
	cout << "�������� ������: ";
	gets_s(nameTh, 99);
	while (nameTh == NULL) {        // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		gets_s(nameTh, 99);
		cin.get();
	}
	cout << "��� ���������: ";
	cin >> yearOfFoundation;
	cin.get();
	while (yearOfFoundation < 1740 || yearOfFoundation > 2021) {  // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> yearOfFoundation;
		cin.get();
	}
	cout << "���������� ����: ";
	cin >> numberOfStages;
	cin.get();
	while (numberOfStages < 0 || numberOfStages > 5) {  // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> numberOfStages;
		cin.get();
	}
	for (int i = 0; i < numberOfStages; i++)
		stages[i].setStage();
}

void Theatre::setTheatre(char* name, int year, int countStages, Stage** masStages) { // ������� ���������� ���������� � ������(��� �����)
	nameTh = new char[100];
	strcpy(nameTh, name);
	yearOfFoundation = year;
	numberOfStages = countStages;
	for (int i = 0; i < numberOfStages; i++)
		stages[i] = *masStages[i];
}

void Theatre::toString() {         // ������� ������ ���������� � ������
	if (nameTh != NULL && yearOfFoundation != NULL) {
		cout << "��������: ";
		cout << nameTh << endl;
		cout << "��� ���������: ";
		cout << yearOfFoundation << endl;
		cout << "����� ����: ";
		cout << numberOfStages << endl;
		int count = 0;
		for (int i = 0; i < numberOfStages; i++) {
			count += stages[i].getNumberOfPerformances();
			cout << "����� �" << i + 1 << ':' << endl;
			stages[i].toString();
		}
		cout << "����� ����������: " << count << endl;
		/*cout << "����� �������: ";
		cout << theatre.numberOfActors << endl;
		cout << "����� ���������� ������������� ������: ";
		cout << theatre.numberOfStageDirectors << endl;*/
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void Theatre::addStage() {  // ���������� ����� � �����
	stages[numberOfStages].setStage();
	numberOfStages = numberOfStages + 1;
}

void Theatre::addStage(char name[50], int capacity, int countPerf, Performance performances[]) {  // ���������� ����� � �����
	stages[numberOfStages].setStage(name, capacity, countPerf, performances);
	numberOfStages = numberOfStages + 1;
}

void Theatre::delStage(int numStage) {  // �������� ����� �� ������
	if (numStage >= 0 && numStage < numberOfStages) {
		for (int i = numStage; i < numberOfStages - 1; i++) {
			stages[i] = stages[i + 1];
		}
		stages[numberOfStages - 1] = {};
		numberOfStages--;
	}
	else
		cout << "����� ����� ������ ���� � ���������� �� 0 ��" << numberOfStages - 1 << " (�������)." << endl;
}