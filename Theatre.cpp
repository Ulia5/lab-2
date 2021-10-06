#include "Theatre.h"

void Theatre::setTheatre() {                      // Функция заполнения информации о театре
	nameTh = new char[100];
	cout << "Название театра: ";
	gets_s(nameTh, 100);
	while (nameTh == NULL) {        // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> nameTh;
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
	/*cout << "Количество сцен: ";
	cin >> theatre.numberOfStages;
	cin.get();
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = setStage();*/
}

void Theatre::setTheatre(char* name, int year/*, int numberOfStages, stage stages[5]*/) { // Функция заполнения информации о театре(без ввода)
	nameTh = new char[100];
	nameTh = name;
	yearOfFoundation = year;
	/*theatre.numberOfStages = numberOfStages;
	for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[i] = stages[i];*/
}

void Theatre::toString() {         // Функция вывода информации о театре
	if (nameTh != NULL && yearOfFoundation != NULL) {
		cout << "Название: ";
		cout << nameTh << endl;
		cout << "Год основания: ";
		cout << yearOfFoundation << endl;
		/*cout << "Всего сцен: ";
		cout << theatre.numberOfStages << endl;
		int count = 0;
		for (int i = 0; i < theatre.numberOfStages; i++) {
			count += theatre.stages[i].numberOfPerformances;
			cout << "Сцена №" << i + 1 << ':' << endl;
			printStage(theatre.stages[i]);
		}
		cout << "Всего спектаклей: " << count << endl;
		cout << "Всего актеров: ";
		cout << theatre.numberOfActors << endl;
		cout << "Всего работников постановочной группы: ";
		cout << theatre.numberOfStageDirectors << endl;*/
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

/*void addStage(theatre* theatre) {  // Добавление сцены в театр
	theatre->stages[theatre->numberOfStages] = setStage();
	theatre->numberOfStages = theatre->numberOfStages + 1;
	
}

void delStage(theatre *theatre, int numStage) {  // Удаление сцены из театра
	if (numStage >= 0 && numStage < theatre->numberOfStages) {
		for (int i = numStage; i < theatre->numberOfStages - 1; i++) {
			theatre->stages[i] = theatre->stages[i + 1];
		}
		theatre->stages[theatre->numberOfStages - 1] = {};
		theatre->numberOfStages = theatre->numberOfStages - 1;
	}
	else
		cout << "Номер сцены должен быть в промежутке от 0 до" << theatre->numberOfStages - 1 << " (включая)." << endl;
}*/