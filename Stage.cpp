#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::setStage() {   // Функция заполнение полей структуры
	cout << "\tНазвание сцены: ";
	gets_s(nameSt, 49);
	while (nameSt == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		gets_s(nameSt, 49);
	};
	cout << "\tВместимость зала: ";
	cin >> hallCapacity;
	cin.get();
	while (hallCapacity < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> hallCapacity;
		cin.get();
	}
	cout << "\tКоличество постановок: ";
	cin >> numberOfPerformances;
	cin.get();
	for (int i = 0; i < numberOfPerformances; i++)
			performances[i]->setPerformance();
}

void Stage::setStage(char name[50], int capacity, int countPerf, Performance* performancesNew[]) {
	strcpy(nameSt, name);
	hallCapacity = capacity;
	numberOfPerformances = countPerf;
	for (int i = 0; i < numberOfPerformances; i++)
		performances[i] = performancesNew[i];
}

void Stage::toString() { // Функция вывода информации о сцене
	if (nameSt != NULL) {
		cout << "Инфорцация о сцене ";
		cout << nameSt << ":" << endl;
		cout << "\tВместимость зала: ";
		cout << hallCapacity << endl;
		cout << "\tПостановок на сцене: ";
		cout << numberOfPerformances << endl;
		for (int i = 0; i < numberOfPerformances; i++) {
			cout << "\tПостановка №" << i + 1 << ':' << endl;
			performances[i]->toString();
		}
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}

void Stage::addPerformance() { // Добавление постановки
	performances[numberOfPerformances]->setPerformance();
	numberOfPerformances++;
}

void Stage::addPerformance(char* namePerf, int performanceTime, int ageRestrictions) { // Добавление постановки
	performances[numberOfPerformances]->setPerformance(namePerf, performanceTime, ageRestrictions);
	numberOfPerformances++;
}

void Stage::delPerformance(int numPerformance) {  // Удаление постановки
	if (numPerformance >= 0 && numPerformance < numberOfPerformances) {
		for (int i = numPerformance; i < numberOfPerformances - 1; i++) {
			performances[i] = performances[i + 1];
		}
		performances[numberOfPerformances - 1] = {};
		numberOfPerformances--;
	}
	else
		cout << "Номер постановки должен быть в промежутке от 0 до " << numberOfPerformances - 1 << " (включая)." << endl;
}

int Stage::getNumberOfPerformances() {
	return numberOfPerformances;
}

Performance* Stage::getPerformance(int number) {
	return performances[number];
}