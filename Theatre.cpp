#define _CRT_SECURE_NO_WARNINGS
#include "Theatre.h"

void Theatre::setTheatre() {                      // Функция заполнения информации о театре
	nameTh = new char[100];
	cout << "Название театра: ";
	gets_s(nameTh, 99);
	while (nameTh == NULL) {        // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		gets_s(nameTh, 99);
		cin.get();
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

void Theatre::setTheatre(char* name, int year, int countStages, Stage** masStages) { // Функция заполнения информации о театре(без ввода)
	nameTh = new char[100];
	strcpy(nameTh, name);
	yearOfFoundation = year;
	numberOfStages = countStages;
	for (int i = 0; i < numberOfStages; i++)
		stages[i] = *masStages[i];
}

void Theatre::toString() {         // Функция вывода информации о театре
	if (nameTh != NULL && yearOfFoundation != NULL) {
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
		/*cout << "Всего актеров: ";
		cout << theatre.numberOfActors << endl;
		cout << "Всего работников постановочной группы: ";
		cout << theatre.numberOfStageDirectors << endl;*/
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

void Theatre::addStage() {  // Добавление сцены в театр
	stages[numberOfStages].setStage();
	numberOfStages = numberOfStages + 1;
}

void Theatre::addStage(char name[50], int capacity, int countPerf, Performance performances[]) {  // Добавление сцены в театр
	stages[numberOfStages].setStage(name, capacity, countPerf, performances);
	numberOfStages = numberOfStages + 1;
}

void Theatre::delStage(int numStage) {  // Удаление сцены из театра
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