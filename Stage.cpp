#define _CRT_SECURE_NO_WARNINGS
#include "Stage.h"

void Stage::setStage() {   // Функция заполнение полей структуры
	cout << "\tНазвание сцены: ";
	gets_s(nameSt, 50);
	while (nameSt == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		gets_s(nameSt, 50);
	};
	cout << "\tВместимость зала: ";
	cin >> hallCapacity;
	cin.get();
	while (hallCapacity < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> hallCapacity;
		cin.get();
	}
	/*cout << "\tКоличество постановок: ";
	cin >> numberOfPerformances;
	cin.get();
	for (int i = 0; i < numberOfPerformances; i++)
			performances[i] = setPerformance();*/
}

void Stage::setStage(char name[50], int capacity/*,  performance performances[]*/) {
	strcpy(nameSt, name);
	hallCapacity = capacity;
	/*numberOfPerformances = Performances;
	for (int i = 0; i < numberOfPerformances; i++)
		performances[i] = performances[i];*/
}

void Stage::toString() { // Функция вывода информации о сцене
	if (nameSt != NULL) {
		cout << "Инфорцация о сцене ";
		cout << nameSt << ":" << endl;
		cout << "\tВместимость зала: ";
		cout << hallCapacity << endl;
		/*cout << "\tПостановок на сцене: ";
		cout << stage.numberOfPerformances << endl;
		for (int i = 0; i < stage.numberOfPerformances; i++) {
			cout << "\tПостановка №" << i + 1 << ':' << endl;
			printPerformance(stage.performances[i]);
		}*/
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}

/*void addPerformance(stage* stage) { // Добавление постановки
	stage->performances[stage->numberOfPerformances] = setPerformance();
	stage->numberOfPerformances++;
}

void delPerformance(stage *stage, int numPerformance) {  // Удаление постановки
	if (numPerformance >= 0 && numPerformance < stage->numberOfPerformances) {
		for (int i = numPerformance; i < stage->numberOfPerformances - 1; i++) {
			stage->performances[i] = stage->performances[i + 1];
		}
		stage->performances[stage->numberOfPerformances - 1] = {};
		stage->numberOfPerformances--;
	}
	else
		cout << "Номер постановки должен быть в промежутке от 0 до" << stage->numberOfPerformances - 1 << " (включая)." << endl;
}*/