#include "StageDirector.h"
void StageDirector::setStageDirector(Theatre* jobPlaceNew) 
{	// Функция заполнения информации о Работнике постановочной группы
	cout << "\tИмя работника постановочной группы: ";
	cin >> nameDir;
	cout << "\tФамилия работника постановочной группы: ";
	cin >> surnameDir;
	cout << "\tВозраст работника постановочной группы: ";
	cin >> ageDir;
	cin.get();
	jobPlace = jobPlaceNew;
	jobPlaceNew->addStageDirector();
}

void StageDirector::setStageDirector(string name, char* surname, int age, Theatre* jobPlaceNew) 
{	// Функция заполнения информации о Работнике постановочной группы(без ввода)
	nameDir = name;
	surnameDir = surname;
	ageDir = age;
	jobPlace = jobPlaceNew;
	jobPlaceNew->addStageDirector();
}

void StageDirector::toString() 
{	// Вывод информации о Работнике постановочной группы
	if (!nameDir.empty()) {
		cout << "Информация о работнике постановочной группы:" << endl;
		cout << "Имя и фамилия: ";
		cout << nameDir << ' ' << surnameDir << endl;
		cout << "Возраст: ";
		cout << ageDir << endl;
		cout << "Место работы: ";
		cout << jobPlace->getNameTh() << endl;
		cout << "Количество работ: ";
		cout << numProjects << endl;
		if (numProjects > 0) {
			cout << "Такие постановки как: " << endl;
			for (int i = 0; i < numProjects; i++)
				cout << i + 1 << ") " << performanceDir[i].getNamePerf() << endl;
		}
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void StageDirector::addPerformanceDir(Performance* performance) 
{	// Добавление Постановки в список работ
	performanceDir[numProjects] = *performance;
	performanceDir[numProjects].addStageDirector();
	performance->addStageDirector();
	numProjects++;
}

void StageDirector::delPerformanceDir(Performance* performance) 
{	// Удаление Постановки из списка работ
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < numProjects; i++)
		if (performanceDir[i].getNamePerf() == performance->getNamePerf()) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < numProjects - 1; i++) {
			performanceDir[i] = performanceDir[i + 1];
		}
		performanceDir[numProjects - 1] = {};
		numProjects--;
		performance->delStageDirector();
	}
	else
		cout << "Таких постановок не найдено!" << endl;
}