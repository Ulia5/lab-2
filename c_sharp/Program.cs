using System;
using System.Text;

namespace c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int numStage_1 = 1, numPerf_1 = 1;
            Performance[] performance_1 = new Performance[numPerf_1];
            performance_1[0] = new Performance("Юнона и Авось", 250, 2000);
            Stage[] stage_1 = new Stage[numStage_1];
            stage_1[0] = new Stage("Большая", 560, numPerf_1, performance_1);
            Theatre theatre = new Theatre("Драматический", 1990, numStage_1, stage_1);
            theatre.toPrint();
            theatre.getStage(0).addPerformance();
            theatre.getStage(0).addPerformance(new Performance("Гроза", 300, 1999));
            theatre.toPrint();
            theatre.getStage(0).delPerformance(1);
            theatre.toPrint();
        }
    }
}