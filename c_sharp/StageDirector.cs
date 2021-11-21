using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
	class StageDirector
	{   // Описание класса Работник сцены
		private String nameDir;     // Имя
		private String surnameDir;  // Фамилия
		private int ageDir = 0;     // Возраст
		private int roles = 0;      // Количетво ролей
		private Theatre jobPlace;   // Место работы
		private Performance[] performanceDir = new Performance[50]; // Постановки, с участием данного Работника

		public StageDirector(Theatre theatre)
		{   // Конструктор Работника (без параметров)
			this.nameDir = toWriteNameDir();
			this.surnameDir = toWriteSurnameDir();
			this.ageDir = toWriteAgeDir();
			this.jobPlace = theatre;
			jobPlace.increasingNumberOfStageDirectors();
			Console.WriteLine();
		}

		public StageDirector(String name, String surname, int age, Theatre theatre)
		{   // Конструктор Работника (с параметрами)
			this.nameDir = name;
			this.surnameDir = surname;
			this.ageDir = age;
			this.jobPlace = theatre;
			jobPlace.increasingNumberOfStageDirectors();
		}

		public String getName()
		{   // Возвращение имени Работника
			return nameDir;
		}

		public String getSurname()
		{   // Возвращение фамилии Работника
			return surnameDir;
		}

		public int getAge()
		{   // Возвращение возраста
			return ageDir;
		}

		public Theatre getJobPlace()
		{   // Возвращение места работы
			return jobPlace;
		}

		public Performance getPerformanceDir(int num)
		{   // Возвращение списка работ
			return performanceDir[num];
		}

		public int getRoles()
		{   // Возвращение кол-ва постановок
			return roles;
		}

		public void toPrint()
		{   // Вывод информации о Работнике
			Console.WriteLine("Имя и фамилия: " + getName() + ' ' + getSurname());
			Console.WriteLine("Возраст: " + getAge());
			Console.WriteLine("Место работы: " + getJobPlace().getNameTh());
			Console.WriteLine("Количество работ: " + getRoles());
			if (getRoles() > 0)
			{
				Console.WriteLine("Такие постановки как: ");
				for (int i = 0; i < getRoles(); i++)
					Console.WriteLine((i + 1) + ") " + getPerformanceDir(i).getNamePerf());
			}
			Console.WriteLine();
		}

		public void addPerformanceAct(Performance performance)
		{   // Добавление постановки в список работ
			performanceDir[getRoles()] = performance;
			performanceDir[getRoles()].addStageDirector();
			addRoles();
		}

		public void delPerformanceDir(Performance performance)
		{ // Удаление постановки из списка работ
			bool flag = false;
			int numPerf = 0;
			for (int i = 0; i < getRoles(); i++)
				if (performanceDir[i].getNamePerf() == performance.getNamePerf())
				{
					flag = true;
					numPerf = i;
				}
			if (flag)
			{
				for (int i = numPerf; i < roles - 1; i++)
				{
					performanceDir[i] = performanceDir[i + 1];
				}
				performanceDir[roles - 1] = null;
				delRoles();
				performance.delStageDirector();
			}
			else
				Console.WriteLine("Такой постановки не найдено!");
		}

		private String toWriteNameDir()
		{   // Ввод имени Работника
			Console.Write("Имя Работника: ");
			string name = Console.ReadLine();
			while (String.IsNullOrEmpty(name))
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Имя Работника: ");
				name = Console.ReadLine();
			}
			return name;
		}

		private string toWriteSurnameDir()
		{   // Ввод фамилии Рабботника
			Console.Write("Фамилия Работника: ");
			string surname = Console.ReadLine();
			while (String.IsNullOrEmpty(surname))
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Фамилия Работника: ");
				surname = Console.ReadLine();
			}
			return surname;
		}

		private int toWriteAgeDir()
		{   // Ввод возраста Работника
			Console.Write("Возраст Работника: ");
			int age = Convert.ToInt32(Console.ReadLine());
			while (age <= 0)
			{
				Console.WriteLine("Неверный формат ввода!");
				Console.Write("Возраст Работника: ");
				age = Convert.ToInt32(Console.ReadLine());
			}
			return age;
		}

		private void addRoles()
		{   // Добавление роли
			roles++;
		}

		private void delRoles()
		{   // Удаление роли
			roles--;
		}
	}
}