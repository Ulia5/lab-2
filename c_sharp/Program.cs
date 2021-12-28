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
            Stage[] stages_1 = new Stage[2];
            Performance[] performance = new Performance[2];
            performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
            performance[1] = new Performance("Любовь и голуби", 180, 1990);
            stages_1[0] = new Stage("Большая", 600, 2, performance);
            Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
            Theatre theatre_2 = new Theatre("Музыкальный", 2000, 1, stages_1);
            Actor[] actors = new Actor[2];
            actors[0] = new Actor("Михаил", "Боярский", 65, theatre_1);
            actors[0] = new Actor("Михаил", "Коровин", 35, theatre_2);
            Console.WriteLine("Задание №1\n");
            try
            {
                performance[1] = new Performance(Console.ReadLine());
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }

        }
    }
}