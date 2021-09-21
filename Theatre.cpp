#include "Theatre.h"

theatre setTheatre() {                      // ������� ���������� ���������� � ������
	theatre theatre = {};
	theatre.nameTh = (char*)malloc(100);
	cout << "�������� ������: ";
	cin >> theatre.nameTh;
	while (theatre.nameTh == NULL) {        // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> theatre.nameTh;
	}
	cout << "��� ���������: ";
	cin >> theatre.yearOfFoundation;
	while (theatre.yearOfFoundation < 0) {  // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> theatre.yearOfFoundation;
	}
	cout << "���������� ����: ";
	cin >> theatre.numberOfStages;
	/*for (int i = 0; i < theatre.numberOfStages; i++)
		theatre.stages[theatre.numberOfStages] = setStage();*/
	cout << "���������� �������: ";
	cin >> theatre.numberOfActors;
	/*for (int i = 0; i < theatre.numberOfActors; i++)
		theatre.actors[theatre.numberOfActors] = setActor();*/
	cout << "��������� ���������� ������������� ������: ";
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

void printTheatre(theatre theatre) {         // ������� ������ ���������� � ������
	if (theatre.nameTh != NULL) {
		cout << "���������� � ������: ";
		cout << theatre.nameTh << endl;
		cout << "\t��� ���������: ";
		cout << theatre.yearOfFoundation << endl;
		cout << "\t����� ����: ";
		cout << theatre.numberOfStages << endl;
		int count = 0;
		/*for (int i = 0; i < theatre.numberOfStages; i++) {
			count += theatre.stages[i].numberOfPerformances;
			cout << "\t����� �" << i + 1 << ':' << endl;
			printStage(theatre.stages[i]);
		}*/
		cout << "\t����� ����������: " + count << endl;
		cout << "\t����� �������: ";
		cout << theatre.numberOfActors << endl;
		/*for (int i = 0; i < theatre.numberOfActors; i++) {
			cout << "\t����� �" << i + 1 << ':' << endl;
			printActor(theatre.actors[i]);
		}*/
		cout << "\t����� ���������� ������������� ������: ";
		cout << theatre.numberOfStageDirectors << endl;
		/*for (int i = 0; i < theatre.numberOfStageDirectors; i++) {
			cout << "\t�������� ������������� ������ �: " << i + 1 << ':' << endl;
			printStageDirector(theatre.stageDirectors[i]);
		}*/
	}
	else
		cout << "��� ������ ��������� ��� ����!" << endl;
}

/*void addStage(theatre theatre) {     // ���������� ����� � �����
	theatre.stages[theatre.numberOfStages] = setStage();
	theatre.numberOfStages++;
}*/

/*void delStage(theatre theatre, int numStage) {  // �������� ����� �� ������
	if (numStage >= 0 && numStage < theatre.numberOfStages) {
		for (int i = numStage; i < theatre.numberOfStages - 1; i++) {
			theatre.stages[i] = theatre.stages[i + 1];
		}
		theatre.stages[theatre.numberOfStages - 1] = {};
		theatre.numberOfStages--;
	}
	else
		cout << "����� ����� ������ ���� � ���������� �� 0 ��" << theatre.numberOfStages - 1 << " (�������)." << endl;
}*/

/*void addActor(theatre theatre) {     // ���������� ������ � �����
	theatre.actors[theatre.numberOfActors] = setActor();
	theatre.numberOfActors++;
}*/

/*void delActor(theatre theatre, int numActor) {  // �������� ������ �� ������
	if (numActor >= 0 && numActor < theatre.numberOfActors) {
		for (int i = numActor; i < theatre.numberOfActors - 1; i++) {
			theatre.actors[i] = theatre.actors[i + 1];
		}
		theatre.actors[theatre.numberOfActors - 1] = {};
		theatre.numberOfActors--;
	}
	else
		cout << "����� ������ ������ ���� � ���������� �� 0 ��" << theatre.numberOfActors - 1 << " (�������)." << endl;
}*/

/*void addStageDirector(theatre theatre) {   // ���������� ��������� ������������� ������ � �����
	theatre.stageDirectors[theatre.numberOfStageDirectors] = setStageDirector();
	theatre.numberOfStageDirectors++;
}*/

/*void delStageDirector(theatre theatre, int numStageDirector) {  // �������� ��������� ������������� ������ �� ������
	if (numStageDirector >= 0 && numStageDirector < theatre.numberOfStageDirectors) {
		for (int i = numStageDirector; i < theatre.numberOfStageDirectors - 1; i++) {
			theatre.stageDirectors[i] = theatre.stageDirectors[i + 1];
		}
		theatre.stageDirectors[theatre.numberOfStageDirectors - 1] = {};
		theatre.numberOfStageDirectors--;
	}
	else
		cout << "����� ��������� ������������� ������ ������ ���� � ���������� �� 0 ��" << theatre.numberOfStageDirectors - 1 << " (�������)." << endl;
}*/