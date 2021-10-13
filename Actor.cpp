#include "Actor.h"

void Actor::setActor(Theatre* jobPlaceNew) { // Функция заполнения информации об Актере
	nameAct = (char*)malloc(50);
	surnameAct = (char*)malloc(50);
	cout << "\tИмя актера: ";
	gets_s(nameAct, 49);
	cout << "\tФамилия актера: ";
	gets_s(surnameAct, 49);
	cout << "\tВозраст актера: ";
	cin >> ageAct;
	cin.get();
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::setActor(char* name, char* surname, int age, Theatre* jobPlaceNew) {
	// Функция заполнения информации об Актере(без ввода)
	nameAct = name;
	surnameAct = surname;
	ageAct = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::toString() { // Вывод информации об Актере
	if (nameAct != NULL) {
		cout << "Информация об актере:" << endl;
		cout << "Имя и фамилия: ";
		cout << nameAct << ' ' << surnameAct << endl;
		cout << "Возраст: ";
		cout << ageAct << endl;
		cout << "Место работы: ";
		cout << jobPlace->getNameTh() << endl;
		cout << "Количество ролей: ";
		cout << roles << endl;
		if (roles > 0) {
			cout << "В таких постановках как: " << endl;
			for (int i = 0; i < roles; i++)
				cout << i + 1 << ") " << performanceAct[i].getNamePerf() << endl;
		}
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void Actor::addPerformanceAct(Performance* performance) { // Добавление Постановки в список ролей
	performanceAct[roles] = *performance;
	performanceAct[roles].addActor();
	performance->addActor();
	roles++;
}

void Actor::delPerformanceAct(Performance* performance) { // Удаление Постановки из списка ролей
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
		cout << "Таких постановок не найдено!" << endl;
}