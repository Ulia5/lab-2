#define _CRT_SECURE_NO_WARNINGS
#include "Performance.h"

void Performance::setPerformance() {                 // Функция заполнения информации о постановке
	namePerf = (char*)malloc(50);
	cout << "\t\tНазвание постановки: ";
	gets_s(namePerf, 49);
	while (namePerf == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> namePerf;
		cin.get();
	};
	cout << "\t\tВремя постановки (в минутах): ";
	cin >> perfomanceTime;
	cin.get();
	while (perfomanceTime < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> perfomanceTime;
		cin.get();
	}
	cout << "\t\tГод премьеры: ";
	cin >> ageRestrictions;
	cin.get();
	while (ageRestrictions < 1740 || ageRestrictions > 2021) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> ageRestrictions;
		cin.get();
	}
}

void Performance::setPerformance(char* name, int time, int age) {  
	// Функция заполнения информации о постановке(без ввода)
	namePerf = new char[100];
	strcpy(namePerf, name);
	perfomanceTime = time;
	ageRestrictions = age;
}

void Performance::toString() { // Вывод информации о постановке
	if (namePerf != NULL) {
		cout << "Инфорцация о постановке:" << endl;
		cout << "\t\tНаименование постановки: ";
		cout << namePerf << endl;
		cout << "\t\tВремя постановки (в минутах): ";
		cout << perfomanceTime << endl;
		cout << "\t\tГод премьеры: ";
		cout << ageRestrictions << endl;
		cout << "\t\tАктеров в постановке: ";
		cout << numberOfActors << endl;
		cout << "\t\tРаботников постановочной группы в постановке: ";
		cout << numberOfStageDirectors << endl;
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}

char* Performance::getNamePerf() {
	return namePerf;
}

void Performance::addActor() {
	numberOfActors++;
}

void Performance::delActor() {
	numberOfActors--;
}

void Performance::addStageDirector() {
	numberOfStageDirectors++;
}

void Performance::delStageDirector() {
	numberOfStageDirectors--;
}