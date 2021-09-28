#include "StageDirector.h"

stageDirector setStageDirector(theatre* jobPlace) { // Функция заполнения информации о Работнике постановочной группы
	stageDirector stageDirector = {};
	stageDirector.nameDir = (char*)malloc(50);
	stageDirector.surnameDir = (char*)malloc(50);
	cout << "\tИмя работника постановочной группы: ";
	gets_s(stageDirector.nameDir, 50);
	cout << "\tФамилия работника постановочной группы: ";
	gets_s(stageDirector.surnameDir, 50);
	cout << "\tВозраст работника постановочной группы: ";
	cin >> stageDirector.ageDir;
	cin.get();
	stageDirector.jobPlace = *jobPlace;
	jobPlace->numberOfStageDirectors++;
	return stageDirector;
}

stageDirector setStageDirector(char* nameDir, char* surnameDir, int ageDir, theatre* jobPlace) {
	// Функция заполнения информации о Работнике постановочной группы(без ввода)
	stageDirector stageDirector = {};
	stageDirector.nameDir = nameDir;
	stageDirector.surnameDir = surnameDir;
	stageDirector.ageDir = ageDir;
	stageDirector.jobPlace = *jobPlace;
	jobPlace->numberOfStageDirectors++;
	return stageDirector;
}

void printStageDirector(stageDirector stageDirector) { // Вывод информации о Работнике постановочной группы
	if (stageDirector.nameDir != NULL) {
		cout << "Информация о работнике постановочной группы:" << endl;
		cout << "Имя и фамилия: ";
		cout << stageDirector.nameDir << ' ' << stageDirector.surnameDir << endl;
		cout << "Возраст: ";
		cout << stageDirector.ageDir << endl;
		cout << "Место работы: ";
		cout << stageDirector.jobPlace.nameTh << endl;
		cout << "Количество работ: ";
		cout << stageDirector.numProjects << endl;
		if (stageDirector.numProjects > 0) {
			cout << "Такие постановки как: " << endl;
			for (int i = 0; i < stageDirector.numProjects; i++)
				cout << i + 1 << ") " << stageDirector.performanceDir[i].namePerf << endl;
		}
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void addPerformanceDir(stageDirector* stageDirector, performance* performance) { // Добавление Постановки в список работ
	stageDirector->performanceDir[stageDirector->numProjects] = *performance;
	stageDirector->numProjects++;
	performance->numberOfStageDirectors++;
}

void delPerformanceDir(stageDirector* stageDirector, performance* performance) { // Удаление Постановки из списка работ
	bool flag = 0;
	int numPerf = 0;
	for (int i = 0; i < stageDirector->numProjects; i++)
		if (stageDirector->performanceDir[i].namePerf == performance->namePerf) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < stageDirector->numProjects - 1; i++) {
			stageDirector->performanceDir[i] = stageDirector->performanceDir[i + 1];
		}
		stageDirector->performanceDir[stageDirector->numProjects - 1] = {};
		stageDirector->numProjects--;
		performance->numberOfStageDirectors--;
	}
	else
		cout << "Таких постановок не найдено!" << endl;
}