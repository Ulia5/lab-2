#include "Performance.h"

performance setPerformance() {
	performance performance = {};
	performance.namePerf = (char*)malloc(50);
	cout << "\t�������� ����������: ";
	gets_s(performance.namePerf, 50);
	while (performance.namePerf == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.namePerf;
		cin.get();
	};
	cout << "\t����� ���������� (� �������): ";
	cin >> performance.perfomanceTime;
	cin.get();
	while (performance.perfomanceTime < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.perfomanceTime;
		cin.get();
	}
	cout << "\t��� ��������: ";
	cin >> performance.ageRestrictions;
	cin.get();
	while (performance.ageRestrictions < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.ageRestrictions;
		cin.get();
	}
	cout << "\t���������� �������: ";
	cin >> performance.numberOfActors;
	cin.get();
	/*cout << "������, ����������� � ����������:" << endl;
	for (int i = 0; i < performance.numberOfActors; i++)
		performance.actors[i] = setStageDirector();*/
	cout << "\t���������� ���������� ������������� ������: ";
	cin >> performance.numberOfStageDirectors;
	cin.get();
	/*cout << "��������� ������������� ������, ����������� � ����������: " << endl;
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
		cout << "���������� � ����������:" << endl;
		cout << "\t������������ ����������: ";
		cout << performance.namePerf << endl;
		cout << "\t����� ���������� (� �������): ";
		cout << performance.perfomanceTime << endl;
		cout << "\t��� ��������: ";
		cout << performance.ageRestrictions << endl;
		cout << "������� � ����������: ";
		cout << performance.numberOfActors << endl;
		/*cout << "������, ����������� � ����������:" << endl;
		for (int i = 0; i < performance.numberOfActors; i++) {
			cout << "\t����� �" << i + 1 << ':' << endl;
			printActor(performance.actors[i]);
		}*/
		cout << "���������� ������������� ������ � ����������: ";
		cout << performance.numberOfStageDirectors << endl;
		/*cout << "��������� ������������� ������, ����������� � ����������:" << endl;
		for (int i = 0; i < performance.numberOsStageDirectors; i++) {
			cout << "\t�������� ������������� ������ �" << i + 1 << ':' << endl;
			printPerformance(performance.stageDirectors[i]);
		}*/
	}
	else
		cout << "���������� ��������� ���������!" << endl;
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
		cout << "����� ������ ������ ���� � ���������� �� 0 �� " << performance->numberOfActors - 1
		<< " (�������)." << endl;
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
		cout << "����� ��������� ������������� ������ ������ ���� � ���������� �� 0 �� " << theatre->numberOfActors - 1
		<< " (�������)." << endl;
}*/