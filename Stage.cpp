#include "Stage.h"

stage setStage() {   // ������� ���������� ����� ���������
	stage stage = {};
	stage.nameSt = (char*)malloc(50);
	cout << "\t�������� �����: ";
	gets_s(stage.nameSt, 50);
	while (stage.nameSt == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> stage.nameSt;
	};
	cout << "\t����������� ����: ";
	cin >> stage.hallCapacity;
	while (stage.hallCapacity < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> stage.hallCapacity;
	}
	cout << "\t���������� ����������: ";
	cin >> stage.numberOfPerformances;
	cin.get();
	for (int i = 0; i < stage.numberOfPerformances; i++)
			stage.performances[i] = setPerformance();
	return stage;
}

stage setStage(char* nameSt, int hallCapacity, int numberOfPerformances, performance performances[]) {
	stage stage = {};
	stage.nameSt = nameSt;
	stage.hallCapacity = hallCapacity;
	stage.numberOfPerformances = numberOfPerformances;
	for (int i = 0; i < stage.numberOfPerformances; i++)
		stage.performances[i] = performances[i];
	return stage;
}

void printStage(stage stage) { // ������� ������ ���������� � �����
	if (stage.nameSt != NULL) {
		cout << "���������� � ����� ";
		cout << stage.nameSt << ":" << endl;
		cout << "\t����������� ����: ";
		cout << stage.hallCapacity << endl;
		cout << "\t���������� �� �����: ";
		cout << stage.numberOfPerformances << endl;
		for (int i = 0; i < stage.numberOfPerformances; i++) {
			cout << "\t���������� �" << i + 1 << ':' << endl;
			printPerformance(stage.performances[i]);
		}
	}
	else
		cout << "���������� ��������� ���������!" << endl;
}

void addPerformance(stage *stage) { // ���������� ����������
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
}