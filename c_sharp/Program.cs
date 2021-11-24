using System;
using System.Text;

namespace c_sharp
{
    class Program
    {
        public static void changeAge (ref int age)
        { // Увеличение возроста на 1(ref)
            age++;
        }

        public static void changeAge1(out int age)
        { // Увеличение возроста на 1(out)
            age = 28;
        }
        static void Main(string[] args)
        {
            int numStage_1 = 2, numPerf_1 = 1;
            Performance[] performance_1 = new Performance[numPerf_1];
            performance_1[0] = new Performance("Юнона и Авось", 250, 2000);
            Stage[] stage_1 = new Stage[numStage_1];
            stage_1[0] = new Stage("Большая", 560, numPerf_1, performance_1);
            stage_1[1] = new Stage("Средняя", 360, numPerf_1, performance_1);
            Theatre theatre = new Theatre("Драматический", 1990, numStage_1, stage_1);
            Actor actor_1 = new Actor("Олег", "Орлов", theatre);
            int a = 30;
            actor_1.Age = a;
            StageDirector sd_1 = new StageDirector("Михаил", "Сидоров", 38, theatre);
            StageDirector sd_2 = new StageDirector("Сергей", "Петров", 34, theatre);
            // Задание №1
            Console.WriteLine("Задание №1:\n");
            actor_1.toPrint();
            Console.WriteLine("\nЗадание №2:\n");
            theatre.toPrint();
            Console.WriteLine("\nЗадание №3:\n");
            changeAge(ref a);
            actor_1.Age = a;
            actor_1.toPrint();
            int b;
            changeAge1(out b);
            actor_1.Age = b;
            actor_1.toPrint();
        }
    }
}