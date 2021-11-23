#define _CRT_SECURE_NO_WARNINGS
#include "Theatre.h"

// Инициализация статической переменной, содержащей общ. кол-во актеров в Театрах
int Theatre::allActors = 0;

void Theatre::countAllAct(Theatre th) 
{	// Подсчет общего кол-ва актеров во всех Театрах
	allActors += th.getNumberOfActors();
}

int Theatre::getAllAct()
{	// Возвращение общего кол-ва актеров в Театрах
	return allActors;
}

// Инициализация статической переменной, содержащей общ. кол-во работников в Театрах
int Theatre::allStageDirectors = 0;

void Theatre::countAllDir(Theatre th)
{	// Подсчет общего кол-ва работников во всех Театрах
	allStageDirectors += th.getNumberOfStageDirectors();
}

int Theatre::getAllDir()
{	// Возвращение общего кол-ва работников в Театрах
	return allStageDirectors;
}

void Theatre::setTheatre()
{	// Функция заполнения информации о театре
	cout << "Название театра: ";
	cin >> nameTh;
	while (nameTh.empty()) {        // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> nameTh;
	}
	cout << "Год основания: ";
	cin >> yearOfFoundation;
	cin.get();
	while (yearOfFoundation < 1740 || yearOfFoundation > 2021) {  // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> yearOfFoundation;
		cin.get();
	}
	cout << "Количество сцен: ";
	cin >> numberOfStages;
	cin.get();
	while (numberOfStages < 0 || numberOfStages > 5) {  // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> numberOfStages;
		cin.get();
	}
	for (int i = 0; i < numberOfStages; i++)
		stages[i].setStage();
}

void Theatre::setTheatre(string name, int year, int countStages, Stage** masStages) 
{   // Функция заполнения информации о театре(без ввода)
	nameTh = name;
	yearOfFoundation = year;
	numberOfStages = countStages;
	for (int i = 0; i < numberOfStages; i++)
		stages[i] = *masStages[i];
}

void Theatre::toString() 
{   // Функция вывода информации о театре
	if (!nameTh.empty() && yearOfFoundation != NULL) {
		cout << "Название: ";
		cout << nameTh << endl;
		cout << "Год основания: ";
		cout << yearOfFoundation << endl;
		cout << "Всего сцен: ";
		cout << numberOfStages << endl;
		int count = 0;
		for (int i = 0; i < numberOfStages; i++) {
			count += stages[i].getNumberOfPerformances();
			cout << "Сцена №" << i + 1 << ':' << endl;
			stages[i].toString();
		}
		cout << "Всего спектаклей: " << count << endl;
		cout << "Всего актеров: ";
		cout << numberOfActors << endl;
		cout << "Всего работников постановочной группы: ";
		cout << numberOfStageDirectors << endl;
		cout << endl;
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void Theatre::addStage() 
{   // Добавление сцены в театр
	stages[numberOfStages].setStage();
	numberOfStages = numberOfStages + 1;
}

void Theatre::addStage(string name, int capacity, int countPerf, Performance* performances[]) 
{   // Добавление сцены в театр
	stages[numberOfStages].setStage(name, capacity, countPerf, performances);
	numberOfStages = numberOfStages + 1;
}

void Theatre::delStage(int numStage) 
{   // Удаление сцены из театра
	if (numStage >= 0 && numStage < numberOfStages) {
		for (int i = numStage; i < numberOfStages - 1; i++) {
			stages[i] = stages[i + 1];
		}
		stages[numberOfStages - 1] = {};
		numberOfStages--;
	}
	else
		cout << "Номер сцены должен быть в промежутке от 0 до" << numberOfStages - 1 << " (включая)." << endl;
}

void Theatre::addActor() 
{   // Увеличение кол-ва актеров
	numberOfActors++;
}

void Theatre::addStageDirector() 
{   // Увеличение кол-ва работников
	numberOfStageDirectors++;
}
string Theatre::getNameTh() 
{   // Возвращение названия Театра
	return nameTh;
}

Stage* Theatre::getStages(int number) 
{   // Возвращение элемента из массива сцен 
	return &stages[number];
}

int Theatre::getNumberOfActors()
{	// Возвращение кол-ва актеров в Театре
	return numberOfActors;
}

int Theatre::getNumberOfStageDirectors()
{	// Возвращение кол-ва работников в Театре
	return numberOfStageDirectors;
}