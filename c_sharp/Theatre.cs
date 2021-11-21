using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Theatre
    {   // Описание класса Театр
        int numberOfStages = 0;             // Количество сцен
        Stage[] stages = new Stage[5];      // Сцены
        int numberOfActors = 0;             // Количество актеров
        int numberOfStageDirectors = 0;     // Количество работников постановочной группы
        string nameTh;                      // Название театра
        int yearOfFoundation = 0;           // Год основания

        public Theatre()
        { // Конструктор Театра (без параметров)
            this.nameTh = toWriteName();
            this.yearOfFoundation = toWriteYear();
            this.numberOfStages = toWriteNumberOfStages();
            this.stages = toWriteStage();
            Console.WriteLine();
        }

        public Theatre(String name, int year, int num, Stage[] stages)
        {   // Конструктор Театра (с параметрами)
            this.nameTh = name;
            this.yearOfFoundation = year;
            this.numberOfStages = num;
            this.stages = stages;
        }

        public string getNameTh()
        {   // Возвращение названия Театра
            return nameTh;
        }

        public int getYearOfFoundation()
        {   // Возвращение года основания
            return yearOfFoundation;
        }

        public int getNumberOfStages()
        {   // Возвращение коло-ва сцен
            return numberOfStages;
        }

        public Stage getStage (int num)
        {   // Возвращение сцены num
            return stages[num];
        }

        public int getNumberOfActors()
        {   // Возвращение кол-ва актеров
            return numberOfActors;
        }

        public int getNumberOfStageDirectors()
        {
            return numberOfStageDirectors;
        }

        public void toPrint()
        { // Функция вывода информации о Театре
            Console.WriteLine("Название театра: " + getNameTh());
            Console.WriteLine("Год основания: " + getYearOfFoundation());
            Console.WriteLine("Количество актеров: " + getNumberOfActors());
            Console.WriteLine("Количество работников сцены: " + getNumberOfStageDirectors());
            Console.WriteLine("Количество сцен: " + getNumberOfStages());
            int count = 0;
            for(int i = 0; i < getNumberOfStages(); i++)
            {
            Console.WriteLine();
                count += stages[i].getNumberOfPerformances();
                Console.WriteLine("Сцена №" + (i + 1) + ':');
                stages[i].toPrint();
            }
            Console.WriteLine();
        }

        public void addStage()
        {   // Добавление сцены (без параметров)
            if (getNumberOfStages() < 5)
            {
                Stage[] newStages = new Stage[5];
                for (int i = 0; i < getNumberOfStages(); i++)
                {
                    newStages[i] = getStage(i);
                }
                newStages[getNumberOfStages()] = new Stage();
                stages = newStages;
                increasingNumberOfStages();
            }
            else
                Console.WriteLine("Максимально кол-во сцен: 5!");
            Console.WriteLine();
        }

        public void addStage(Stage stage)
        {   // Добавление сцены (с параметрами)
            if (getNumberOfStages() < 5)
            {
                Stage[] newStages = new Stage[5];
                for(int i = 0; i < getNumberOfStages(); i++)
                {
                    newStages[i] = getStage(i);
                }
                newStages[getNumberOfStages()] = stage;
                stages = newStages;
                increasingNumberOfStages();
            }
            else
                Console.WriteLine("Максимально кол-во сцен: 5!");
        }

        public void delStage(int numStage)
        {   // Удаление сцены
            if (numStage >= 0 && numStage < getNumberOfStages())
            {
                for (int i = numStage; i < getNumberOfStages() - 1; i++)
                {
                    stages[i] = stages[i + 1];
                }
                decreasingNumberOfStages();
            }
            else
                Console.WriteLine("Номер сцены должен быть в промежутке от 0 до " + (numberOfStages - 1) + " (включая).");
        }

        private string toWriteName()
        {   // Ввод названия Театра
            Console.Write("Название театра: ");
            string name = Console.ReadLine();
            while (String.IsNullOrEmpty(name))
            {
                Console.WriteLine("Неверный формат ввода!");
                Console.Write("Название театра: ");
                name = Console.ReadLine();
            }
            return name;
        }

        private int toWriteYear()
        {   // Ввод года основания
            Console.Write("Год основания: ");
            int year = Convert.ToInt32(Console.ReadLine());
            while (year > 2021 || year < 1740)
            {
                Console.WriteLine("Неверный формат ввода!");
                Console.Write("Год основания: ");
                year = Convert.ToInt32(Console.ReadLine());
            }
            return year;
        }

        private int toWriteNumberOfStages()
        {   // Ввод кол-ва сцен
            Console.Write("Количество сцен: ");
            int num = Convert.ToInt32(Console.ReadLine());
            while (num > 5 || num <= 0)
            {
                Console.WriteLine("Неверный формат ввода!");
                Console.Write("Количество сцен: ");
                num = Convert.ToInt32(Console.ReadLine());
            }
            return num;
        }

        private Stage[] toWriteStage()
        {   // Вввод информации о сценах
            Stage[] stages = new Stage[getNumberOfStages()];
            for (int i = 0; i < getNumberOfStages(); i++)
            {
                stages[i] = new Stage();
            }
            return stages;
        }

        private void increasingNumberOfStages()
        {   // Увеличение кол-ва сцен
            numberOfStages++;
        }

        private void decreasingNumberOfStages()
        {   // Уменьшение кол-ва сцен
            numberOfStages--;
        }

        public void increasingNumberOfActors()
        {   // Увеличение кол-ва актеров
            numberOfActors++;
        }

        private void decreaseNumberOfActors()
        {     // Уменьшение кол-ва актеров
            numberOfStages--;
        }

        public void increasingNumberOfStageDirectors()
        {   // Увеличение кол-ва работников сцены
            numberOfStageDirectors++;
        }

        private void decreasingNumberOfStageDirectors()
        {   // Уменьшение кол-ва работников сцены
            numberOfStageDirectors--;
        }
    }
}
