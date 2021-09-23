#include "Performance.h"

performance setPerformance() {
	performance performance = {};
	performance.namePerf = (char*)malloc(50);
	cout << "\tНазвание постановки: ";
	gets_s(performance.namePerf, 50);
	while (performance.namePerf == NULL) {     // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.namePerf;
		cin.get();
	};
	cout << "\tВремя постановки (в минутах): ";
	cin >> performance.perfomanceTime;
	cin.get();
	while (performance.perfomanceTime < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.perfomanceTime;
		cin.get();
	}
	cout << "\tГод премьеры: ";
	cin >> performance.ageRestrictions;
	cin.get();
	while (performance.ageRestrictions < 0) { // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> performance.ageRestrictions;
		cin.get();
	}
	cout << "\tКоличество актеров: ";
	cin >> performance.numberOfActors;
	cin.get();
	/*cout << "Актеры, участвующие в постановке:" << endl;
	for (int i = 0; i < performance.numberOfActors; i++)
		performance.actors[i] = setStageDirector();*/
	cout << "\tКоличество работников постановочной группы: ";
	cin >> performance.numberOfStageDirectors;
	cin.get();
	/*cout << "Работники постановочной группы, участвующие в постановке: " << endl;
	for (int i = 0; i < performance.numberOsStageDirectors; i++)
		performance.stageDirectors[i] = setStageDirector();*/
	return performance;
}

performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions
	, int numberOfActors/*, actor actors[50]*/, int numberOfStageDirectors/*, stageDirector stageDirectors[25]*/) {
	performance performance = {};
	performance.namePerf = namePerf;
	performance.perfomanceTime = performanceTime;
	performance.ageRestrictions = ageRestrictions;
	performance.numberOfActors = numberOfActors;
	/*for (int i  = 0; i < numberOfActors; i++)
		performance.actors[i] = actors[i];*/
	performance.numberOfStageDirectors = numberOfStageDirectors;
	/*for (int i  = 0; i < numberOsStageDirectors; i++)
		performance.stageDirectors[i] = stageDirectors[i];
	*/
	return performance;
}

void printPerformance(performance performance) {
	if (performance.namePerf != NULL) {
		cout << "Инфорцация о постановке:" << endl;
		cout << "\tНаименование постановки: ";
		cout << performance.namePerf << endl;
		cout << "\tВремя постановки (в минутах): ";
		cout << performance.perfomanceTime << endl;
		cout << "\tГод премьеры: ";
		cout << performance.ageRestrictions << endl;
		cout << "Актеров в постановке: ";
		cout << performance.numberOfActors << endl;
		/*cout << "Актеры, участвующие в постановке:" << endl;
		for (int i = 0; i < performance.numberOfActors; i++) {
			cout << "\tАктер №" << i + 1 << ':' << endl;
			printActor(performance.actors[i]);
		}*/
		cout << "Работников постановочной группы в постановке: ";
		cout << performance.numberOfStageDirectors << endl;
		/*cout << "Работники постановочной группы, участвующие в постановке:" << endl;
		for (int i = 0; i < performance.numberOsStageDirectors; i++) {
			cout << "\tРаботник постановочной группы №" << i + 1 << ':' << endl;
			printPerformance(performance.stageDirectors[i]);
		}*/
	}
	else
		cout << "Необходимо заполнить структуру!" << endl;
}

/*void addActor(performance* performance, int numActor) {
	performance->actors[performance->numberOfActors] = actor[numActor];
	performance->numberOfActors++;
}*/

/*void delActor(performance* performance, int numActors) {
	if (numActors >= 0 && numActors < performance->numberOfActors) {
		for (int i = numActors; i < performance->numberOfActors - 1; i++) {
			performance->actors[i] = performance->actors[i + 1];
		}
		performance->actors[performance->numberOfActors - 1] = {};
		performance->numberOfActors--;
	}
	else
		cout << "Номер актера должен быть в промежутке от 0 до " << performance->numberOfActors - 1
		<< " (включая)." << endl;
}*/

/*void addStageDirector(stage* stage)
	performance->stageDirectors[performance->numberOfStageDirectors] = setStageDirectors();
	performance->numberOfStageDirectors++;
}

void delStageDirector(stage* stage, int numStageDirectors) {
	if (numStageDirectors >= 0 && numStageDirectors < performance->numStageDirectors) {
		for (int i = numStageDirectors; i < performance->numStageDirectors - 1; i++) {
			performance->stageDirectors[i] = performance->stageDirector[i + 1];
		}
		performance->stageDirectors[performance->numStageDirectors - 1] = {};
		performance->numStageDirectors--;
	}
	else
		cout << "Номер работника постановочной группы должен быть в промежутке от 0 до " << theatre->numberOfActors - 1
		<< " (включая)." << endl;
}*/