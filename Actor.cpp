#include "Actor.h"

void Actor::setActor(Theatre* jobPlaceNew) 
{   // Функция заполнения информации об Актере
	roles = 0;
	cout << "\tИмя актера: ";
	cin >> nameAct;
	while (nameAct.empty()) {		// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> nameAct;
	};
	cout << "\tФамилия актера: ";
	cin >> surnameAct;
	while (surnameAct.empty()) {	// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> surnameAct;
	};
	cout << "\tВозраст актера: ";
	cin >> ageAct;
	while (ageAct < 0) {			// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> ageAct;
	};
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::setActor(string name, string surname, int age, Theatre* jobPlaceNew) 
{	// Функция заполнения информации об Актере(без ввода)
	nameAct = name;
	surnameAct = surname;
	ageAct = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addActor();
}

void Actor::toString() 
{   // Вывод информации об Актере
	if (!nameAct.empty()) {
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
		cout << endl;
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void Actor::addPerformanceAct(Performance* performance) 
{   // Добавление Постановки в список ролей
	performanceAct[roles] = *performance;
	performanceAct[roles].addActor();
	performance->addActor();
	roles++;
}

void Actor::delPerformanceAct(Performance* performance) 
{   // Удаление Постановки из списка ролей
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

int& Actor::age_change()
{	// Изменение возраста Актера
	return ageAct;
}

Actor Actor::operator+ (Actor actor) 
{	// Перегрузка оператора + для сложения списков постановок
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
{	// Перегрузка оператора ++(преф.) для добавления сгенерированной постановки
	Performance* perf = new Performance;
	perf->somePerf();
	if (roles < 50)
		addPerformanceAct(perf);
	else
		cout << "Достигнуто максимальное количество постановок!" << endl;
	return *this;
}

Actor Actor::operator++ (int notused) 
{	// Перегрузка оператора ++(пост.) для добавления сгенерированной постановки
	Actor act = *this;
	Performance* perf = new Performance;
	perf->somePerf();
	if (roles < 50)
		addPerformanceAct(perf);
	else
		cout << "Достигнуто максимальное количество постановок!" << endl;
	return act;

}