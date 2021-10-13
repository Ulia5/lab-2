#include "Actor.h"

void Actor::setActor(Theatre* jobPlaceNew) { // ������� ���������� ���������� �� ������
	nameAct = (char*)malloc(50);
	surnameAct = (char*)malloc(50);
	cout << "\t��� ������: ";
	gets_s(nameAct, 49);
	cout << "\t������� ������: ";
	gets_s(surnameAct, 49);
	cout << "\t������� ������: ";
	cin >> ageAct;
	cin.get();
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::setActor(char* name, char* surname, int age, Theatre* jobPlaceNew) {
	// ������� ���������� ���������� �� ������(��� �����)
	nameAct = name;
	surnameAct = surname;
	ageAct = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::toString() { // ����� ���������� �� ������
	if (nameAct != NULL) {
		cout << "���������� �� ������:" << endl;
		cout << "��� � �������: ";
		cout << nameAct << ' ' << surnameAct << endl;
		cout << "�������: ";
		cout << ageAct << endl;
		cout << "����� ������: ";
		cout << jobPlace->getNameTh() << endl;
		cout << "���������� �����: ";
		cout << roles << endl;
		if (roles > 0) {
			cout << "� ����� ����������� ���: " << endl;
			for (int i = 0; i < roles; i++)
				cout << i + 1 << ") " << performanceAct[i].getNamePerf() << endl;
		}
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void Actor::addPerformanceAct(Performance* performance) { // ���������� ���������� � ������ �����
	performanceAct[roles] = *performance;
	performanceAct[roles].addActor();
	performance->addActor();
	roles++;
}

void Actor::delPerformanceAct(Performance* performance) { // �������� ���������� �� ������ �����
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < roles; i++)
		if (performanceAct[i].getNamePerf() == performance->getNamePerf()) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < roles - 1; i++) {
			performanceAct[i] = performanceAct[i + 1];
		}
		performanceAct[roles - 1] = {};
		roles--;
		performance->delActor();
	}
	else
		cout << "����� ���������� �� �������!" << endl;
}