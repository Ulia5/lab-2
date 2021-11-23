#define _CRT_SECURE_NO_WARNINGS
#include "Performance.h"

void Performance::setPerformance() 
{   // Функция заполнения информации о постановке
	cout << "\t\tНазвание постановки: ";
	cin >> namePerf;
	while (namePerf.empty()) {		// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> namePerf;
	};
	cout << "\t\tВремя постановки (в минутах): ";
	cin >> performanceTime;
	cin.get();
	while (performanceTime < 0) {	// Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performanceTime;
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

void Performance::setPerformance(string name, int time, int age) 
{	// Функция заполнения информации о постановке(без ввода)
	namePerf = name;
	performanceTime = time;
	ageRestrictions = age;
}

void Performance::toString() 
{   // Вывод информации о постановке
	if (!namePerf.empty()) {
		cout << "Инфорцация о постановке:" << endl;
		cout << "\t\tНаименование постановки: ";
		cout << namePerf << endl;
		cout << "\t\tВремя постановки (в минутах): ";
		cout << performanceTime << endl;
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

string Performance::getNamePerf() 
{	// Возвращение названия Постановки
	return namePerf;
}

void Performance::addActor() 
{	// Увеличение кол-ва актеров
	numberOfActors++;
}

void Performance::delActor() 
{	// Уменьшение кол-ва актеров
	numberOfActors--;
}

void Performance::addStageDirector() 
{	// Увеличение кол-ва работников
	numberOfStageDirectors++;
}

void Performance::delStageDirector() 
{	// Увеличение кол-ва работников
	numberOfStageDirectors--;
}

void Performance::somePerf()
{	// Генерация случайной постановки
	srand(1);
	namePerf = "Какая-то постановка №" + to_string(1 + rand() % 50);
	srand(100);
	performanceTime = rand() % 400 + 1;
	srand(1740);
	ageRestrictions = rand() % 2021 + 1;
}