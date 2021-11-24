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
            Theatre theatre_1 = new Theatre("Драматический", 1990, numStage_1, stage_1);
            Theatre theatre_2 = new Theatre("Музыкальный", 1900, numStage_1, stage_1);
            Actor actor_1 = new Actor("Олег", "Орлов", theatre_1);
            int a = 30;
            actor_1.Age = a;
            StageDirector sd_1 = new StageDirector("Михаил", "Сидоров", 38, theatre_1);
            StageDirector sd_2 = new StageDirector("Сергей", "Петров", 34, theatre_2);
            Console.WriteLine("Задание №1\n");
            Console.WriteLine("Актеров в 1м театре: " + (theatre_1.getNumberOfActors()) + ", актеров во 2м театре: " + theatre_2.getNumberOfActors());
            Console.WriteLine("\nЗначение общего количества актеров до обращения к методу: " + Theatre.getAllAct());
            Theatre.countAllAct(theatre_1);
            Theatre.countAllAct(theatre_2);
            Console.WriteLine("\nЗначение общего количества актеров после обращения к методу: " + Theatre.getAllAct());
            Console.WriteLine("\nРаботников в 1м театре: " + theatre_1.getNumberOfStageDirectors() + ", работников во 2м театре: " + theatre_2.getNumberOfStageDirectors());
            Console.WriteLine("\nЗначение общего количества работников до обращения к методу: " + Theatre.getAllDir());
            Theatre.countAllDir(theatre_1);
            Theatre.countAllDir(theatre_2);
            Console.WriteLine("\nЗначение общего количества актеров после обращения к методу: " + Theatre.getAllDir());
        }
    }
}