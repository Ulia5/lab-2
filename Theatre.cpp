#include "Theatre.h"

theatre setTheatre() {                      // ������� ���������� ���������� � ������
	theatre theatre = {};
	theatre.nameTh = (char*)malloc(100);
	cout << "�������� ������: ";
	gets_s(theatre.nameTh, 100);
	while (theatre.nameTh == NULL) {        // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> theatre.nameTh;
		cin.get();
	}
	cout << "��� ���������: ";
	cin >> theatre.yearOfFoundation;
	cin.get();
	while (theatre.yearOfFoundation < 0) {  // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> theatre.yearOfFoundation;
		cin.get();
	}
	cout << "���������� ����: ";
	cin >> theatre.numberOfStages;
	cin.get();
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = setStage();
	return theatre;
}

theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, stage stages[5]) { // ������� ���������� ���������� � ������(��� �����)
	theatre theatre = {};
	theatre.nameTh = (char*)malloc(100);
	theatre.nameTh = nameTh;
	theatre.yearOfFoundation = yearOfFoundation;
	theatre.numberOfStages = numberOfStages;
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = stages[i];
	return theatre;
}

void printTheatre(theatre theatre) {         // ������� ������ ���������� � ������
	if (theatre.nameTh != NULL) {
		cout << "���������� � ������: ";
		cout << theatre.nameTh << endl;
		cout << "��� ���������: ";
		cout << theatre.yearOfFoundation << endl;
		cout << "����� ����: ";
		cout << theatre.numberOfStages << endl;
		int count = 0;
		for (int i = 0; i < theatre.numberOfStages; i++) {
			count += theatre.stages[i].numberOfPerformances;
			cout << "����� �" << i + 1 << ':' << endl;
			printStage(theatre.stages[i]);
		}
		cout << "����� ����������: " << count << endl;
		cout << "����� �������: ";
		cout << theatre.numberOfActors << endl;
		cout << "����� ���������� ������������� ������: ";
		cout << theatre.numberOfStageDirectors << endl;
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void addStage(theatre *theatre) {  // ���������� ����� � �����
	theatre->stages[theatre->numberOfStages] = setStage();
	theatre->numberOfStages = theatre->numberOfStages + 1;
	
}

void delStage(theatre *theatre, int numStage) {  // �������� ����� �� ������
	if (numStage >= 0 && numStage < theatre->numberOfStages) {
		for (int i = numStage; i < theatre->numberOfStages - 1; i++) {
			theatre->stages[i] = theatre->stages[i + 1];
		}
		theatre->stages[theatre->numberOfStages - 1] = {};
		theatre->numberOfStages = theatre->numberOfStages - 1;
	}
	else
		cout << "����� ����� ������ ���� � ���������� �� 0 ��" << theatre->numberOfStages - 1 << " (�������)." << endl;
}