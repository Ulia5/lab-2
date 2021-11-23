#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::setStage() 
{   // Функция заполнение полей структуры (без параметров)
	cout << "\tНазвание сцены: ";
	cin >> nameSt;
	while (nameSt.empty()) {	// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> nameSt;
	};
	cout << "\tВместимость зала: ";
	cin >> hallCapacity;
	cin.get();
	while (hallCapacity < 0) {	// Защита от неверного ввода
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

void Stage::setStage(string name, int capacity, int countPerf, Performance* performancesNew[]) 
{	// // Функция заполнение полей структуры (с параметрами)
	nameSt = name;
	hallCapacity = capacity;
	numberOfPerformances = countPerf;
	for (int i = 0; i < numberOfPerformances; i++)
		performances[i] = performancesNew[i];
}

void Stage::toString() 
{	// Функция вывода информации о сцене
	if (!nameSt.empty()) {
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

void Stage::addPerformance() 
{	// Добавление постановки
	performances[numberOfPerformances]->setPerformance();
	numberOfPerformances++;
}

void Stage::addPerformance(string namePerf, int performanceTime, int ageRestrictions) 
{	// Добавление постановки
	performances[numberOfPerformances]->setPerformance(namePerf, performanceTime, ageRestrictions);
	numberOfPerformances++;
}

void Stage::delPerformance(int numPerformance) 
{   // Удаление постановки
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

int Stage::getNumberOfPerformances() 
{	// Возвращение кол-ва постановок
	return numberOfPerformances;
}

Performance* Stage::getPerformance(int number) 
{	// Возвращение определенной постановки
	return performances[number];
}