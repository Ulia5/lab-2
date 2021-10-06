/*#include "Performance.h"

performance setPerformance() {                 // Функция заполнения информации о постановке
	performance performance = {};
	performance.namePerf = (char*)malloc(50);
	cout << "\t\tНазвание постановки: ";
	gets_s(performance.namePerf, 50);
	while (performance.namePerf == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.namePerf;
		cin.get();
	};
	cout << "\t\tВремя постановки (в минутах): ";
	cin >> performance.perfomanceTime;
	cin.get();
	while (performance.perfomanceTime < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.perfomanceTime;
		cin.get();
	}
	cout << "\t\tГод премьеры: ";
	cin >> performance.ageRestrictions;
	cin.get();
	while (performance.ageRestrictions < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.ageRestrictions;
		cin.get();
	}
	return performance;
}

performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions) {  
	// Функция заполнения информации о постановке(без ввода)
	performance performance = {};
	performance.namePerf = namePerf;
	performance.perfomanceTime = performanceTime;
	performance.ageRestrictions = ageRestrictions;
	return performance;
}

void printPerformance(performance performance) { // Вывод информации о постановке
	if (performance.namePerf != NULL) {
		cout << "Инфорцация о постановке:" << endl;
		cout << "\t\tНаименование постановки: ";
		cout << performance.namePerf << endl;
		cout << "\t\tВремя постановки (в минутах): ";
		cout << performance.perfomanceTime << endl;
		cout << "\t\tГод премьеры: ";
		cout << performance.ageRestrictions << endl;
		cout << "\t\tАктеров в постановке: ";
		cout << performance.numberOfActors << endl;
		cout << "\t\tРаботников постановочной группы в постановке: ";
		cout << performance.numberOfStageDirectors << endl;
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}*/