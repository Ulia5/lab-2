using System;
using System.Text;

namespace c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int numStage_1 = 1, numStage_2 = 1;
            Stage[] stage_1 = new Stage[numStage_1];
            Stage[] stage_2 = new Stage[numStage_2];
            stage_1[0] = new Stage("Большая", 560);
            stage_2[0] = new Stage("Малая", 200);
            Theatre theatre = new Theatre("Драматический", 1990, numStage_1, stage_1);
            theatre.toPrint();
            theatre.addStage();
            theatre.addStage(stage_2[0]);
            theatre.toPrint();
            theatre.delStage(0);
            theatre.toPrint();
        }
    }
}