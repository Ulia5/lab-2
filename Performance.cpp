/*#include "Performance.h"

performance setPerformance() {                 // ������� ���������� ���������� � ����������
	performance performance = {};
	performance.namePerf = (char*)malloc(50);
	cout << "\t\t�������� ����������: ";
	gets_s(performance.namePerf, 50);
	while (performance.namePerf == NULL) {     // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.namePerf;
		cin.get();
	};
	cout << "\t\t����� ���������� (� �������): ";
	cin >> performance.perfomanceTime;
	cin.get();
	while (performance.perfomanceTime < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.perfomanceTime;
		cin.get();
	}
	cout << "\t\t��� ��������: ";
	cin >> performance.ageRestrictions;
	cin.get();
	while (performance.ageRestrictions < 0) { // ������ �� ��������� �����
		cout << "�������� ������ �����!" << endl;
		cin >> performance.ageRestrictions;
		cin.get();
	}
	return performance;
}

performance setPerformance(char* namePerf, int performanceTime, int ageRestrictions) {  
	// ������� ���������� ���������� � ����������(��� �����)
	performance performance = {};
	performance.namePerf = namePerf;
	performance.perfomanceTime = performanceTime;
	performance.ageRestrictions = ageRestrictions;
	return performance;
}

void printPerformance(performance performance) { // ����� ���������� � ����������
	if (performance.namePerf != NULL) {
		cout << "���������� � ����������:" << endl;
		cout << "\t\t������������ ����������: ";
		cout << performance.namePerf << endl;
		cout << "\t\t����� ���������� (� �������): ";
		cout << performance.perfomanceTime << endl;
		cout << "\t\t��� ��������: ";
		cout << performance.ageRestrictions << endl;
		cout << "\t\t������� � ����������: ";
		cout << performance.numberOfActors << endl;
		cout << "\t\t���������� ������������� ������ � ����������: ";
		cout << performance.numberOfStageDirectors << endl;
	}
	else
		cout << "���������� ��������� ���������!" << endl;
}*/