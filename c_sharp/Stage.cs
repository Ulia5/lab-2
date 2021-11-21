using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Stage
	{	// Объявление класса Сцена
		string nameSt;					// Название сцены
		int hallCapacity = 0;			// Вместимость зала
		//int numberOfPerformances = 0; // Количество постановок
		//Performance[] performances = new Performance [50]; // Список постановок

		public Stage()
		{   // Конструктор Сцены (без параметров)
			this.nameSt = toWriteName();
			this.hallCapacity = toWriteCapacity();
			//this.numberOfPerformances = toWriteNumberOfPerformance();
			//this.performances = toWritePerformance();
			Console.WriteLine();
		}

		public Stage(String name, int capacity/*, int numberPerf, Performance performances[]*/)
		{   // Конструктор Сцены (с параметрами)
			this.nameSt = name;
			this.hallCapacity = capacity;
			//this.numberOfPerformances = numberPerf;
			//this.performances = performances;
		}

		public string getNameSt()
        {	// Возвращение названия Сцены
			return nameSt;
        }

		public int getHallCapacity()
        {	// Возвращение вместимости зала
			return hallCapacity;
        }

		public void toPrint()
		{	// Функция вывода информации о театре
			Console.WriteLine("\tНазвание сцены: " + getNameSt());
			Console.WriteLine("\tВместимость зала: " + getHallCapacity());
			Console.WriteLine();
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
	}
}
