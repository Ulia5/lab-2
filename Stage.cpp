#include "Stage.h"

stage setStage() {   // Функция заполнение полей структуры
	stage stage = {};
	stage.nameSt = (char*)malloc(50);
	cout << "\tНазвание сцены: ";
	gets_s(stage.nameSt, 50);
	while (stage.nameSt == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> stage.nameSt;
	};
	cout << "\tВместимость зала: ";
	cin >> stage.hallCapacity;
	while (stage.hallCapacity < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> stage.hallCapacity;
	}
	cout << "\tКоличество постановок: ";
	cin >> stage.numberOfPerformances;
	cin.get();
	for (int i = 0; i < stage.numberOfPerformances; i++)
			stage.performances[i] = setPerformance();
	return stage;
}

stage setStage(char* nameSt, int hallCapacity, int numberOfPerformances, performance performances[]) {
	stage stage = {};
	stage.nameSt = nameSt;
	stage.hallCapacity = hallCapacity;
	stage.numberOfPerformances = numberOfPerformances;
	for (int i = 0; i < stage.numberOfPerformances; i++)
		stage.performances[i] = performances[i];
	return stage;
}

void printStage(stage stage) { // Функция вывода информации о сцене
	if (stage.nameSt != NULL) {
		cout << "Инфорцация о сцене ";
		cout << stage.nameSt << ":" << endl;
		cout << "\tВместимость зала: ";
		cout << stage.hallCapacity << endl;
		cout << "\tПостановок на сцене: ";
		cout << stage.numberOfPerformances << endl;
		for (int i = 0; i < stage.numberOfPerformances; i++) {
			cout << "\tПостановка №" << i + 1 << ':' << endl;
			printPerformance(stage.performances[i]);
		}
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}

void addPerformance(stage *stage) { // Добавление постановки
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
}