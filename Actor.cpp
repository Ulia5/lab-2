#include "Actor.h"

actor setActor(theatre* jobPlace) { // Функция заполнения информации об Актере
	actor actor = {};
	actor.nameAct = (char*)malloc(50);
	actor.surnameAct = (char*)malloc(50);
	cout << "\tИмя актера: ";
	gets_s(actor.nameAct, 50);
	cout << "\tФамилия актера: ";
	gets_s(actor.surnameAct, 50);
	cout << "\tВозраст актера: ";
	cin >> actor.ageAct;
	cin.get();
	actor.jobPlace = *jobPlace;
	jobPlace->numberOfActors++;
	return actor;
}

actor setActor(char* nameAct, char* surnameAct, int ageAct, theatre* jobPlace) {
	// Функция заполнения информации об Актере(без ввода)
	actor actor = {};
	actor.nameAct = nameAct;
	actor.surnameAct = surnameAct;
	actor.ageAct = ageAct;
	actor.jobPlace = *jobPlace;
	jobPlace->numberOfActors++;
	return actor;
}

void printActor(actor actor) { // Вывод информации об Актере
	if (actor.nameAct != NULL) {
		cout << "Информация об актере:" << endl;
		cout << "Имя и фамилия: ";
		cout << actor.nameAct << ' ' << actor.surnameAct << endl;
		cout << "Возраст: ";
		cout << actor.ageAct << endl;
		cout << "Место работы: ";
		cout << actor.jobPlace.nameTh << endl;
		cout << "Количество ролей: ";
		cout << actor.roles << endl;
		if (actor.roles > 0) {
			cout << "В таких постановках как: " << endl;
			for (int i = 0; i < actor.roles; i++)
				cout << i + 1 << ") " << actor.performanceAct[i].namePerf << endl;
		}
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void addPerformanceAct(actor* actor, performance* performance) { // Добавление Постановки в список ролей
	actor->performanceAct[actor->roles] = *performance;
	actor->roles++;
	performance->numberOfActors++;
}

void delPerformanceAct(actor* actor, performance* performance) { // Удаление Постановки из списка ролей
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
		cout << "Таких постановок не найдено!" << endl;
}