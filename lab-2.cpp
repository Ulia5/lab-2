#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Theatre.h"
#include "Actor.h"
#include "StageDirector.h"
#include <locale>
#include <windows.h>

int allPerformances(Theatre th) 
{	// Нахождение общего кол-ва спектаклей в театре
	int num = 0;
	for (int i = 0; i < th.numberOfStages; i++)
		num += th.getStages(i)->getNumberOfPerformances();
	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Объявление и инициализация объектов, используемых в примерах
	Theatre* theatres = new Theatre[3];
	Stage* stages[2]; 
	Performance* performances[2];
	Performance* performances0[1];
	Actor actors[3];
	StageDirector stageDirectors[2];
	for (int i = 0; i < 2; i++) {
		stages[i] = new Stage;
	}
	for (int i = 0; i < 2; i++) {
		performances[i] = new Performance;
	}
	for (int i = 0; i < 1; i++) {
		performances0[i] = new Performance;
	}
	// Заполнение информации об объектах, используемых в примерах
	actors[0].setActor((char*)"Иван", (char*)"Иванов", 32, &theatres[0]);
	actors[1].setActor((char*)"Петр", (char*)"Петров", 32, &theatres[0]);
	stageDirectors[0].setStageDirector((char*)"Игорь", (char*)"Иванов", 23, &theatres[0]);
	stageDirectors[1].setStageDirector((char*)"Павел", (char*)"Петров", 30, &theatres[0]);
	performances[0]->setPerformance("Игра", 200, 2020);
	performances[1]->setPerformance("Мир", 220, 2000);
	performances0[0]->setPerformance("Лира", 120, 2021);
	actors[0].addPerformanceAct(performances[0]);
	actors[0].addPerformanceAct(performances[1]);
	stages[0]->setStage((char*)"Большая сцена", 500, 2, performances);
	stages[1]->setStage((char*)"Малая сцена", 100, 1, performances0);
	theatres[0].setTheatre((char*)"Музыкальный театр", 1990, 2, stages);
	// Пример для 1 задания
	cout << "Задание №1:\n" << endl;
	actors[0].toString();
	actors[0].age_change() = 25;
	actors[0].toString();
	// Пример для 3 задания
	cout << "\nЗадание №3:\n" << endl;
	theatres[0].toString();
	cout << "Всего спектаклей в театрах: "; 
	int num = 0;
	for(int i = 0; i < 3; i++)
		num += allPerformances(theatres[i]);
	cout << num << endl;
	cout << endl;
	// Пример для заданий 2 и 4
	cout << "\nЗадание №2 и №4:\n" << endl;
	Actor newActor;
	newActor.setActor((char*)"Андрей", (char*)"Миронов", 30, &theatres[0]);
	newActor.addPerformanceAct(performances0[0]);
	cout << "Какую из операций вы хотите применить (+ или ++): ";
	string op;
	cin >> op;
	if (op == "+") {
		actors[2] = actors[0] + newActor;
		cout << "Сложение списка спектаклей actors[0] и newActor (actors[0] + newActor):\n" << endl;
		actors[2].toString();
	}
	else
		if (op == "++") {
			cout << "\nКакой из видов вы хотите применить (pref - префиксная, post - постфиксная): ";
			cin >> op;
			if (op == "pref") {
				newActor.setActor((char*)"Михаил", (char*)"Боярский", 60, &theatres[0]);
				actors[2] = ++newActor;
				cout << "\nДобавление к списку спектаклей newActor сгенерированного спектакля(++newActor):\n" << endl;
				cout << "Информация об исходном актере после дейсвия:\n" << endl;
				newActor.toString();
				cout << "Информация о полученном актере после действия:\n" << endl;
				actors[2].toString();
			}
			else
				if (op == "post") {
					newActor.setActor((char*)"Михаил", (char*)"Боярский", 60, &theatres[0]);
					actors[2] = newActor++;
					cout << "\nДобавление к списку спектаклей newActor сгенерированного спектакля(newActor++):\n" << endl;
					cout << "Информация об исходном актере после дейсвия:\n" << endl;
					newActor.toString();
					cout << "Информация о полученном актере после действия:\n" << endl;
					actors[2].toString();
				}
				else
					cout << "Неверный формат ввода!" << endl;
		}
		else
			cout << "Неверный формат ввода!" << endl;
	// Освобождение памяти
	delete[] theatres;
	for (int i = 0; i < 2; i++) {
		delete stages[i];
	}
	for (int i = 0; i < 2; i++) {
		delete performances[i];
	}
	for (int i = 0; i < 1; i++) {
		delete performances0[i];
	}
}
