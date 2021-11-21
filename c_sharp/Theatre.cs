using System;
using System.Collections.Generic;
using System.Text;

namespace c_sharp
{
    class Theatre
    {   // Описание класса Театр
        int numberOfStages = 0;             // Количество сцен
        Stage[] stages = new Stage[5];      // Сцены
        //int numberOfActors = 0;           // Количество актеров
        //int numberOfStageDirectors = 0;   // Количество работников постановочной группы
        string nameTh;                      // Название театра
        int yearOfFoundation = 0;           // Год основания

        public Theatre()
        { // Конструктор Театра (без параметров)
            this.nameTh = toWriteName();
            this.yearOfFoundation = toWriteYear();
            this.numberOfStages = toWriteNumberOfStages();
            this.stages = toWriteStages();
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

        public Stage getStages (int num)
        {   // Возвращение сцены num
            return stages[num];
        }

        public void toPrint()
        { // Функция вывода информации о театре
            Console.WriteLine("Название театра: " + getNameTh());
            Console.WriteLine("Год основания: " + getYearOfFoundation());
            Console.WriteLine("Количество сцен: " + getNumberOfStages());
            //int count = 0;
            for(int i = 0; i < getNumberOfStages(); i++)
            {
            Console.WriteLine();
                //count += stages[i].getNumberOfPerformances();
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
                    newStages[i] = getStages(i);
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
                    newStages[i] = getStages(i);
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

        private Stage[] toWriteStages()
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
        /*private int WriteNumberOfStage()
        {

        }

        private Stage toWriteStages()
        {

        }*/


        /*public void toString()
        { // Функция вывода информации о театре
        if (nameTh != NULL && yearOfFoundation != NULL)
        {
        cout « "Название: ";
        cout « nameTh « endl;
        cout « "Год основания: ";
        cout « yearOfFoundation « endl;
        cout « "Всего сцен: ";
        cout « numberOfStages « endl;
        int count = 0;
        for (int i = 0; i < numberOfStages; i++)
        {
        count += stages[i].getNumberOfPerformances();
        cout « "Сцена №" « i + 1 « ':' « endl;
        stages[i].toString();
        }
        cout « "Всего спектаклей: " « count « endl;
        cout « "Всего актеров: ";
        cout « numberOfActors « endl;
        cout « "Всего работников постановочной группы: ";
        cout « numberOfStageDirectors « endl;
        }
        else
        cout « "Для начала заполните все поля!" « endl;
        }

        void Theatre::addStage()
        { // Добавление сцены в театр
        stages[numberOfStages].setStage();
        numberOfStages = numberOfStages + 1;
        }

        void Theatre::addStage(char name[50], int capacity, int countPerf, Performance* performances[])
        { // Добавление сцены в театр
        stages[numberOfStages].setStage(name, capacity, countPerf, performances);
        numberOfStages = numberOfStages + 1;
        }

        void Theatre::delStage(int numStage)
        { // Удаление сцены из театра
        if (numStage >= 0 && numStage < numberOfStages)
        {
        for (int i = numStage; i < numberOfStages - 1; i++)
        {
        stages[i] = stages[i + 1];
        }
        stages[numberOfStages - 1] = { };
        numberOfStages--;
        }
        else
        cout « "Номер сцены должен быть в промежутке от 0 до" « numberOfStages - 1 « " (включая)." « endl;
        }

        void Theatre::addActor()
        {
        numberOfActors++;
        }

        void Theatre::addStageDirector()
        {
        numberOfStageDirectors++;
        }
        char* Theatre::getNameTh()
        {
        return nameTh;
        }

        Stage* Theatre::getStages(int number)
        {
        return &stages[number];
        }*/
    }
}
