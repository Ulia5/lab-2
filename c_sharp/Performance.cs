using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Performance
	{	// Описание класса Постановка
		string namePerf;			// Название Постановки
		int performanceTime = 0;	// Время Постановки (в минутах)
		int ageRestrictions = 0;    // Год премьеры
		int numberOfActors = 0;		// Количество актеров в Постановке
		int numberOfStageDirectors = 0;  // Количество работников постановочной группы в Постановке

		public Performance()
		{   // Конструктор Постановки (без параметров)
			this.namePerf = toWriteName();
			this.performanceTime = toWritePerformanceTime();
			this.ageRestrictions = toWriteAgeRestrictions();
			Console.WriteLine();
		}

		public Performance(String str)
		{  // Конструктор (ввод всей информации 1 строкой)
			String[] infPerf = str.Split(" ");
			if (infPerf.Length != 3)
			{
				throw new ArgumentException("Wrong format! Correct format: \nИгрок 180 2010");
			}
			this.namePerf = infPerf[0];
			this.performanceTime = Convert.ToInt32(infPerf[1]);
			this.ageRestrictions = Convert.ToInt32(infPerf[2]);
		}


		public Performance(String name, int time,  int age)
		{   // Конструктор Постановки (со всеми параметрами)
			this.namePerf = name;
			this.performanceTime = time;
			this.ageRestrictions = age;
		}

		public string getNamePerf()
        {	// Возвращение названия Постановки
			return namePerf;
        }

		public int getPerformanceTime()
        {	// Возвращение времени Постановки
			return performanceTime;
        }

		public int getAgeRestrictions()
        {	// Возвращение года премьеры
			return ageRestrictions;
        }

		public int getNumberOfActors()
        {	// Возвращение кол-ва актеров
			return numberOfActors;
        }

		public int getNumberOfStageDirectors()
		{
			return numberOfStageDirectors;
		}

		public void toPrint()
        {   // Функция вывода информации о Постановке
			Console.WriteLine("\t\tНазвание постановки: " + getNamePerf());
			Console.WriteLine("\t\tВремя постановки (в минутах): " + getPerformanceTime());
			Console.WriteLine("\t\tГод премьеры: " + getAgeRestrictions());
			Console.WriteLine("\t\tКоличество актеров: " + getNumberOfActors());
			Console.WriteLine("\t\tКоличество работников сцены: " + getNumberOfStageDirectors());
		}

		private string toWriteName()
		{	// Ввод названи Постановки
			Console.Write("\t\tНазвание постановки: ");
			string name = Console.ReadLine();
			while (String.IsNullOrEmpty(name))
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\t\tНазвание постановки: ");
				name = Console.ReadLine();
			}
			return name;
		}

		private int toWritePerformanceTime()
        {   // Ввод времени Постановки
			Console.Write("\t\tВремя постановки (в минутах): ");
			int time = Convert.ToInt32(Console.ReadLine());
			while (time <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\t\tВремя постановки (в минутах): ");
				time = Convert.ToInt32(Console.ReadLine());
			}
			return time;
		}

		private int toWriteAgeRestrictions()
        {   // Ввод года премьеры Постановки
			Console.Write("\t\tГод премьеры: ");
			int age = Convert.ToInt32(Console.ReadLine());
			while (age <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("\t\tГод премьеры: ");
				age = Convert.ToInt32(Console.ReadLine());
			}
			return age;
		}

		public void addActor()
		{   // Добавление актера 
			numberOfActors++;
		}

		public void delActor()
		{   // Удаление актера
			numberOfActors--;
		}

		public void addStageDirector()
		{   // Добавление работника
			numberOfStageDirectors++;
		}

		public void delStageDirector()
		{   // Удаление работника
			numberOfStageDirectors--;
		}
	}
}
