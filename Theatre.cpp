#include "Theatre.h"

void Theatre::setTheatre() {                      // ������� ���������� ���������� � ������
	nameTh = new char[100];
	cout << "�������� ������: ";
	gets_s(nameTh, 100);
	while (nameTh == NULL) {        // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> nameTh;
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
	/*cout << "���������� ����: ";
	cin >> theatre.numberOfStages;
	cin.get();
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = setStage();*/
}

void Theatre::setTheatre(char* name, int year/*, int numberOfStages, stage stages[5]*/) { // ������� ���������� ���������� � ������(��� �����)
	nameTh = new char[100];
	nameTh = name;
	yearOfFoundation = year;
	/*theatre.numberOfStages = numberOfStages;
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = stages[i];*/
}

void Theatre::toString() {         // ������� ������ ���������� � ������
	if (nameTh != NULL && yearOfFoundation != NULL) {
		cout << "��������: ";
		cout << nameTh << endl;
		cout << "��� ���������: ";
		cout << yearOfFoundation << endl;
		/*cout << "����� ����: ";
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
		cout << theatre.numberOfStageDirectors << endl;*/
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

/*void addStage(theatre* theatre) {  // ���������� ����� � �����
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
}*/