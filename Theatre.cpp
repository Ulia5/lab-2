#include "Theatre.h"

theatre setTheatre() {                      // Функция заполнения информации о театре
	theatre theatre = {};
	theatre.nameTh = (char*)malloc(100);
	cout << "Название театра: ";
	cin >> theatre.nameTh;
	while (theatre.nameTh == NULL) {        // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> theatre.nameTh;
	}
	cout << "Год основания: ";
	cin >> theatre.yearOfFoundation;
	while (theatre.yearOfFoundation < 0) {  // Защита от неверного ввода
		cout << "Неверный формат ввода!" << endl;
		cin >> theatre.yearOfFoundation;
	}
	cout << "Количество сцен: ";
	cin >> theatre.numberOfStages;
	/*for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[theatre.numberOfStages] = setStage();*/
	cout << "Количество актеров: ";
	cin >> theatre.numberOfActors;
	/*for (int i = 0; i < theatre.numberOfActors; i++)
		theatre.actors[theatre.numberOfActors] = setActor();*/
	cout << "Колиество работников постановочной группы: ";
	cin >> theatre.numberOfStageDirectors;
	/*for (int i = 0; i < theatre.numberOfStageDirectors; i++)
		theatre.stageDirectors[theatre.numberOfStageDirectors] = setStageDirector();*/
	return theatre;
}

theatre setTheatre(char* nameTh, int yearOfFoundation, int numberOfStages, /*stage stages[5],*/
	int numberOfActors, /*actor actors[50],*/ int numberOfStageDirectors/*, stageDirector stageDirectors[50]*/) {
	theatre theatre = {};
	theatre.nameTh = (char*)malloc(100);
	theatre.nameTh = nameTh;
	theatre.yearOfFoundation = yearOfFoundation;
	theatre.numberOfStages = numberOfStages;
	//theatre.stages = stages;
	theatre.numberOfActors = numberOfActors;
	//theatre.actors = actors;
	theatre.numberOfStageDirectors = numberOfStageDirectors;
	//theatre.stageDirectors = stageDirectors;
	return theatre;
}

void printTheatre(theatre theatre) {         // Функция вывода информации о театре
	if (theatre.nameTh != NULL) {
		cout << "Информация о театре: ";
		cout << theatre.nameTh << endl;
		cout << "\tГод основания: ";
		cout << theatre.yearOfFoundation << endl;
		cout << "\tВсего сцен: ";
		cout << theatre.numberOfStages << endl;
		int count = 0;
		/*for (int i = 0; i < theatre.numberOfStages; i++) {
			count += theatre.stages[i].numberOfPerformances;
			cout << "\tСцена №" << i + 1 << ':' << endl;
			printStage(theatre.stages[i]);
		}*/
		cout << "\tВсего спектаклей: " + count << endl;
		cout << "\tВсего актеров: ";
		cout << theatre.numberOfActors << endl;
		/*for (int i = 0; i < theatre.numberOfActors; i++) {
			cout << "\tАктер №" << i + 1 << ':' << endl;
			printActor(theatre.actors[i]);
		}*/
		cout << "\tВсего работников постановочной группы: ";
		cout << theatre.numberOfStageDirectors << endl;
		/*for (int i = 0; i < theatre.numberOfStageDirectors; i++) {
			cout << "\tРаботник постановочной группы №: " << i + 1 << ':' << endl;
			printStageDirector(theatre.stageDirectors[i]);
		}*/
	}
	else
		cout << "Для начала заполните все поля!" << endl;
}

/*void addStage(theatre theatre) {     // Добавление сцены в театр
	theatre.stages[theatre.numberOfStages] = setStage();
	theatre.numberOfStages++;
}*/

/*void delStage(theatre theatre, int numStage) {  // Удаление сцены из театра
	if (numStage >= 0 && numStage < theatre.numberOfStages) {
		for (int i = numStage; i < theatre.numberOfStages - 1; i++) {
			theatre.stages[i] = theatre.stages[i + 1];
		}
		theatre.stages[theatre.numberOfStages - 1] = {};
		theatre.numberOfStages--;
	}
	else
		cout << "Номер сцены должен быть в промежутке от 0 до" << theatre.numberOfStages - 1 << " (включая)." << endl;
}*/

/*void addActor(theatre theatre) {     // Добавление актера в театр
	theatre.actors[theatre.numberOfActors] = setActor();
	theatre.numberOfActors++;
}*/

/*void delActor(theatre theatre, int numActor) {  // Удаление актера из театра
	if (numActor >= 0 && numActor < theatre.numberOfActors) {
		for (int i = numActor; i < theatre.numberOfActors - 1; i++) {
			theatre.actors[i] = theatre.actors[i + 1];
		}
		theatre.actors[theatre.numberOfActors - 1] = {};
		theatre.numberOfActors--;
	}
	else
		cout << "Номер актера должен быть в промежутке от 0 до" << theatre.numberOfActors - 1 << " (включая)." << endl;
}*/

/*void addStageDirector(theatre theatre) {   // Добавление работника постановочной группы в театр
	theatre.stageDirectors[theatre.numberOfStageDirectors] = setStageDirector();
	theatre.numberOfStageDirectors++;
}*/

/*void delStageDirector(theatre theatre, int numStageDirector) {  // Удаление работника постановочной группы из театра
	if (numStageDirector >= 0 && numStageDirector < theatre.numberOfStageDirectors) {
		for (int i = numStageDirector; i < theatre.numberOfStageDirectors - 1; i++) {
			theatre.stageDirectors[i] = theatre.stageDirectors[i + 1];
		}
		theatre.stageDirectors[theatre.numberOfStageDirectors - 1] = {};
		theatre.numberOfStageDirectors--;
	}
	else
		cout << "Номер работника постановочной группы должен быть в промежутке от 0 до" << theatre.numberOfStageDirectors - 1 << " (включая)." << endl;
}*/