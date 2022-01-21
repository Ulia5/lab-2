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
            Theatre[,] theatre = new Theatre[2,1];
            theatre[0,0] = new Theatre("Драматический", 1990, 1, stages_1);
            theatre[1,0] = new Theatre("Музыкальный", 2000, 1, stages_1);
            Actor[] actors = new Actor[2];
            actors[0] = new Actor("Михаил", "Боярский", 65, theatre[0,0]);
            actors[0] = new Actor("Михаил", "Коровин", 35, theatre[1,0]);
            Console.WriteLine("Задание №1\n");
            Suit newSuit = new Suit("черный", 40, 5000, "фрак");
            newSuit.thingInf();
            Sword newSword = new Sword(5, 10, 10000);
            newSword.thingInf();
        }
    }
}