#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::setStage() {   // ������� ���������� ����� ���������
	cout << "\t�������� �����: ";
	gets_s(nameSt, 50);
	while (nameSt == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		gets_s(nameSt, 50);
	};
	cout << "\t����������� ����: ";
	cin >> hallCapacity;
	cin.get();
	while (hallCapacity < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> hallCapacity;
		cin.get();
	}
	/*cout << "\t���������� ����������: ";
	cin >> numberOfPerformances;
	cin.get();
	for (int i = 0; i < numberOfPerformances; i++)
			performances[i] = setPerformance();*/
}

void Stage::setStage(char name[50], int capacity/*,  performance performances[]*/) {
	strcpy(nameSt, name);
	hallCapacity = capacity;
	/*numberOfPerformances = Performances;
	for (int i = 0; i < numberOfPerformances; i++)
		performances[i] = performances[i];*/
}

void Stage::toString() { // ������� ������ ���������� � �����
	if (nameSt != NULL) {
		cout << "���������� � ����� ";
		cout << nameSt << ":" << endl;
		cout << "\t����������� ����: ";
		cout << hallCapacity << endl;
		/*cout << "\t���������� �� �����: ";
		cout << stage.numberOfPerformances << endl;
		for (int i = 0; i < stage.numberOfPerformances; i++) {
			cout << "\t���������� �" << i + 1 << ':' << endl;
			printPerformance(stage.performances[i]);
		}*/
	}
	else
		cout << "���������� ��������� ���������!" << endl;
}

/*void addPerformance(stage* stage) { // ���������� ����������
	stage->performances[stage->numberOfPerformances] = setPerformance();
	stage->numberOfPerformances++;
}

void delPerformance(stage *stage, int numPerformance) {  // �������� ����������
	if (numPerformance >= 0 && numPerformance < stage->numberOfPerformances) {
		for (int i = numPerformance; i < stage->numberOfPerformances - 1; i++) {
			stage->performances[i] = stage->performances[i + 1];
		}
		stage->performances[stage->numberOfPerformances - 1] = {};
		stage->numberOfPerformances--;
	}
	else
		cout << "����� ���������� ������ ���� � ���������� �� 0 ��" << stage->numberOfPerformances - 1 << " (�������)." << endl;
}*/