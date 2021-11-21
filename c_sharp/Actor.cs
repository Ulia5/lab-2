using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Actor
    {	// Описание класса Актер
		private String nameAct;     // Имя
		private String surnameAct;  // Фамилия
		private int ageAct = 0;     // Возраст
		private int roles = 0;      // Количетво ролей
		private Theatre jobPlace;   // Место работы
		private Performance[] performanceAct = new Performance[50]; // Постановки, с участием данного Актера

		public Actor(Theatre theatre)
		{   // Конструктор Актера (без параметров)
			this.nameAct = toWriteNameAct();
			this.surnameAct = toWriteSurnameAct();
			this.ageAct = toWriteAgeAct();
			this.jobPlace = theatre;
			jobPlace.increasingNumberOfActors();
			Console.WriteLine();
		}

		public Actor(String name, String surname, int age, Theatre theatre)
		{   // Конструктор Актера (с параметрами)
			this.nameAct = name;
			this.surnameAct = surname;
			this.ageAct = age;
			this.jobPlace = theatre;
			jobPlace.increasingNumberOfActors();
		}

		public String getNameAct()
		{	// Возвращение имени Актера
			return nameAct;
		}

		public String getSurnameAct()
		{	// Возвращение фамилии Актера
			return surnameAct;
		}

		public int getAgeAct()
		{   // Возвращение возраста
			return ageAct;
		}

		public Theatre getJobPlace()
		{   // Возвращение места работ
			return jobPlace;
		}

		public Performance getPerformanceAct(int num)
		{   // Возвращение списка работы
			return performanceAct[num];
		}

		public int getRoles()
		{   // Возвращение кол-ва ролей
			return roles;
		}

		public void toPrint()
		{   // Вывод информации об Актере 
			Console.WriteLine("Имя и фамилия: " + getNameAct() + ' ' + getSurnameAct());
			Console.WriteLine("Возраст: " + getAgeAct());
			Console.WriteLine("Место работы: " + getJobPlace().getNameTh());
			Console.WriteLine("Количество ролей: " + getRoles());
			if (getRoles() > 0)
			{
				Console.WriteLine("В таких постановках как: ");
				for (int i = 0; i < getRoles(); i++)
					Console.WriteLine((i + 1) + ") " + getPerformanceAct(i).getNamePerf());
			}
			Console.WriteLine();
		}

		public void addPerformanceAct(Performance performance)
		{	// Добавление постановки в список ролей 
			performanceAct[getRoles()] = performance;
			performanceAct[getRoles()].addActor();
			addRoles();
		}

		public void delPerformanceAct(Performance performance)
		{ // Удаление постановки из списка ролей
			bool flag = false;
			int numPerf = 0;
			for (int i = 0; i < getRoles(); i++)
				if (performanceAct[i].getNamePerf() == performance.getNamePerf())
				{
					flag = true;
					numPerf = i;
				}
			if (flag)
			{
				for (int i = numPerf; i < roles - 1; i++)
				{
					performanceAct[i] = performanceAct[i + 1];
				}
				performanceAct[roles - 1] = null;
				delRoles();
				performance.delActor();
			}
			else
				Console.WriteLine("Такой постановки не найдено!");
		}

		private String toWriteNameAct()
		{   // Ввод имени Актера
			Console.Write("Имя актера: ");
			string name = Console.ReadLine();
			while (String.IsNullOrEmpty(name))
			{                        
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Имя актера: ");
				name = Console.ReadLine();
			}
			return name;
		}

		private string toWriteSurnameAct()
		{   // Ввод фамилии Актера
			Console.Write("Фамилия актера: ");
			string surname = Console.ReadLine();
			while (String.IsNullOrEmpty(surname))
			{   
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Фамилия актера: ");
				surname = Console.ReadLine();
			}
			return surname;
		}

		private int toWriteAgeAct()
		{   // Ввод возраста Актера
			Console.Write("Возраст актера: ");
			int age = Convert.ToInt32(Console.ReadLine());
			while (age <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Возраст актера: ");
				age = Convert.ToInt32(Console.ReadLine());
			}
			return age;
		}

		private void addRoles()
		{   // Добавление роли
			roles++;
		}

		private void delRoles()
		{	// Удаление роли
			roles--;
		}
	}
}
