#include "Actor.h"

actor setActor(theatre* jobPlace) { // ������� ���������� ���������� �� ������
	actor actor = {};
	actor.nameAct = (char*)malloc(50);
	actor.surnameAct = (char*)malloc(50);
	cout << "\t��� ������: ";
	gets_s(actor.nameAct, 50);
	cout << "\t������� ������: ";
	gets_s(actor.surnameAct, 50);
	cout << "\t������� ������: ";
	cin >> actor.ageAct;
	cin.get();
	actor.jobPlace = *jobPlace;
	jobPlace->numberOfActors++;
	return actor;
}

actor setActor(char* nameAct, char* surnameAct, int ageAct, theatre* jobPlace) {
	// ������� ���������� ���������� �� ������(��� �����)
	actor actor = {};
	actor.nameAct = nameAct;
	actor.surnameAct = surnameAct;
	actor.ageAct = ageAct;
	actor.jobPlace = *jobPlace;
	jobPlace->numberOfActors++;
	return actor;
}

void printActor(actor actor) { // ����� ���������� �� ������
	if (actor.nameAct != NULL) {
		cout << "���������� �� ������:" << endl;
		cout << "��� � �������: ";
		cout << actor.nameAct << ' ' << actor.surnameAct << endl;
		cout << "�������: ";
		cout << actor.ageAct << endl;
		cout << "����� ������: ";
		cout << actor.jobPlace.nameTh << endl;
		cout << "���������� �����: ";
		cout << actor.roles << endl;
		if (actor.roles > 0) {
			cout << "� ����� ����������� ���: " << endl;
			for (int i = 0; i < actor.roles; i++)
				cout << i + 1 << ") " << actor.performanceAct[i].namePerf << endl;
		}
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void addPerformanceAct(actor* actor, performance* performance) { // ���������� ���������� � ������ �����
	actor->performanceAct[actor->roles] = *performance;
	actor->roles++;
	performance->numberOfActors++;
}

void delPerformanceAct(actor* actor, performance* performance) { // �������� ���������� �� ������ �����
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < actor->roles; i++)
		if (actor->performanceAct[i].namePerf == performance->namePerf) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < actor->roles - 1; i++) {
			actor->performanceAct[i] = actor->performanceAct[i + 1];
		}
		actor->performanceAct[actor->roles - 1] = {};
		actor->roles--;
		performance->numberOfActors--;
	}
	else
		cout << "����� ���������� �� �������!" << endl;
}