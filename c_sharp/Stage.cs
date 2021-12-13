using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Stage
	{	// Объявление класса Сцена
		string nameSt;					// Название сцены
		int hallCapacity = 0;			// Вместимость зала
		int numberOfPerformances = 0;	// Количество постановок
		Performance[] performances = new Performance [50]; // Список постановок

		public Stage()
		{   // Конструктор Сцены (без параметров)
			this.nameSt = toWriteName();
			this.hallCapacity = toWriteCapacity();
			this.numberOfPerformances = toWriteNumberOfPerformance();
			this.performances = toWritePerformance();
			Console.WriteLine();
		}

		public Stage(String name)
		{   // Конструктор Сцены (с одним параметром)
			this.nameSt = name;
			this.hallCapacity = toWriteCapacity();
			this.numberOfPerformances = toWriteNumberOfPerformance();
			this.performances = toWritePerformance();
			Console.WriteLine();
		}

		public Stage(String name, int capacity, int numberPerf, Performance[] performances)
		{   // Конструктор Сцены (со всеми параметрами)
			this.nameSt = name;
			this.hallCapacity = capacity;
			this.numberOfPerformances = numberPerf;
			this.performances = performances;
		}

		public string getNameSt()
        {	// Возвращение названия Сцены
			return nameSt;
        }

		public int getHallCapacity()
        {	// Возвращение вместимости зала
			return hallCapacity;
        }

		public int getNumberOfPerformances()
        {	// Возвращение кол-ва постановок
			return numberOfPerformances;
        }

		public Performance getPerformance(int num)
        {
			return performances[num];
        }

		public void toPrint()
		{	// Функция вывода информации о Сцене
			Console.WriteLine("\tНазвание сцены: " + getNameSt());
			Console.WriteLine("\tВместимость зала: " + getHallCapacity());
			Console.WriteLine("\tКоличество постановок: " + getNumberOfPerformances());
			for(int i = 0; i < getNumberOfPerformances(); i++)
            {
				Console.WriteLine("\tПостановка №" + (i + 1) + ':');
				performances[i].toPrint();
			}
			Console.WriteLine();
		}

		public void addPerformance()
		{   // Добавление постановки (без параметров)
			if (getNumberOfPerformances() < 50)
			{
				Performance[] newPerformances = new Performance[5];
				for (int i = 0; i < getNumberOfPerformances(); i++)
				{
					newPerformances[i] = getPerformance(i);
				}
				newPerformances[getNumberOfPerformances()] = new Performance();
				performances = newPerformances;
				increasingNumberOfPerformances();
			}
			else
				Console.WriteLine("Максимально кол-во постановок: 50!");
		}

		public void addPerformance(Performance performance)
		{   // Добавление постановки (с параметрами)
			if (getNumberOfPerformances() < 5)
			{
				Performance[] newPerformances = new Performance[5];
				for (int i = 0; i < getNumberOfPerformances(); i++)
				{
					newPerformances[i] = getPerformance(i);
				}
				newPerformances[getNumberOfPerformances()] = performance;
				performances = newPerformances;
				increasingNumberOfPerformances();
			}
			else
				Console.WriteLine("Максимально кол-во постановок: 50!");
			Console.WriteLine();
		}

		public void delPerformance(int numPerformance)
		{   // Удаление постановки
			if (numPerformance >= 0 && numPerformance < getNumberOfPerformances())
			{
				for (int i = numPerformance; i < getNumberOfPerformances() - 1; i++)
				{
					performances[i] = performances[i + 1];
				}
				decreasingNumberOfPerformances();
			}
			else
				Console.WriteLine("Номер постановки должен быть в промежутке от 0 до " + (numberOfPerformances - 1) + " (включая).");
		}

		private string toWriteName()
        {	// Ввод названи Сцены
			Console.Write("\tНазвание сцены: ");
			string name = Console.ReadLine();
			while (String.IsNullOrEmpty(name))
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\tНазвание сцены: ");
				name = Console.ReadLine();
			}
			return name;
		}

		private int toWriteCapacity()
		{	// Ввод вместимости зала
			Console.Write("\tВместимость зала: ");
			int capacity = Convert.ToInt32(Console.ReadLine());
			while (capacity <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\tВместимость зала: ");
				capacity = Convert.ToInt32(Console.ReadLine());
			}
			return capacity;
		}

		private int toWriteNumberOfPerformance()
		{	// Ввод кол-ва постановок
			Console.Write("\tКоличество постановок: ");
			int num = Convert.ToInt32(Console.ReadLine());
			while (num <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\tКоличество постановок: ");
				num = Convert.ToInt32(Console.ReadLine());
			}
			return num;
		}

		private Performance[] toWritePerformance()
		{   // Вввод информации о постановках
			Performance[] performances = new Performance[getNumberOfPerformances()];
			for (int i = 0; i < getNumberOfPerformances(); i++)
			{
				performances[i] = new Performance();
			}
			return performances;
		}

		private void increasingNumberOfPerformances()
        {
			numberOfPerformances++;
        }

		private void decreasingNumberOfPerformances()
		{
			numberOfPerformances--;
		}
	}
}
