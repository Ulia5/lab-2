#include "Actor.h"

void Actor::setActor(Theatre* jobPlaceNew) 
{   // ������� ���������� ���������� �� ������
	roles = 0;
	cout << "\t��� ������: ";
	cin >> nameAct;
	while (nameAct.empty()) {		// ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> nameAct;
	};
	cout << "\t������� ������: ";
	cin >> surnameAct;
	while (surnameAct.empty()) {	// ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> surnameAct;
	};
	cout << "\t������� ������: ";
	cin >> ageAct;
	while (ageAct < 0) {			// ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> ageAct;
	};
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::setActor(string name, string surname, int age, Theatre* jobPlaceNew) 
{	// ������� ���������� ���������� �� ������(��� �����)
	nameAct = name;
	surnameAct = surname;
	ageAct = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::toString() 
{   // ����� ���������� �� ������
	if (!nameAct.empty()) {
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
		cout << endl;
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

void Actor::addPerformanceAct(Performance* performance) 
{   // ���������� ���������� � ������ �����
	performanceAct[roles] = *performance;
	performanceAct[roles].addActor();
	performance->addActor();
	roles++;
}

void Actor::delPerformanceAct(Performance* performance) 
{   // �������� ���������� �� ������ �����
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

int& Actor::age_change()
{	// ��������� �������� ������
	return ageAct;
}

Actor Actor::operator+ (Actor actor) 
{	// ���������� ��������� + ��� �������� ������� ����������
	Actor newActor;
	newActor.nameAct = actor.nameAct;
	newActor.surnameAct = actor.surnameAct;
	newActor.ageAct = actor.ageAct;
	newActor.roles = roles + actor.roles;
	newActor.jobPlace = actor.jobPlace;
	if (newActor.roles > 50)
		newActor.roles = 50;
	int count = 0;
	for (int i = 0; i < roles; i++) {
		newActor.performanceAct[count] = performanceAct[i];
		count++;
	}
	for (int i = 0; i < actor.roles && i < (50 - roles); i++) {
		newActor.performanceAct[count] = actor.performanceAct[i];
		count++;
	}
	return newActor;
}

Actor Actor::operator++ () 
{	// ���������� ��������� ++(����.) ��� ���������� ��������������� ����������
	Performance* perf = new Performance;
	perf->somePerf();
	if (roles < 50)
		addPerformanceAct(perf);
	else
		cout << "���������� ������������ ���������� ����������!" << endl;
	return *this;
}

Actor Actor::operator++ (int notused) 
{	// ���������� ��������� ++(����.) ��� ���������� ��������������� ����������
	Actor act = *this;
	Performance* perf = new Performance;
	perf->somePerf();
	if (roles < 50)
		addPerformanceAct(perf);
	else
		cout << "���������� ������������ ���������� ����������!" << endl;
	return act;

}