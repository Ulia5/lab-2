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
            Actor actor_1 = new Actor("Олег", "Орлов", 25, theatre);
            StageDirector sd_1 = new StageDirector(theatre);
            StageDirector sd_2 = new StageDirector("Сергей", "Петров", 34, theatre);
            sd_2.toPrint();
            sd_1.addPerformanceAct(theatre.getStage(0).getPerformance(0));
            sd_2.addPerformanceAct(theatre.getStage(0).getPerformance(0));
            theatre.toPrint();
            sd_1.toPrint();
            sd_1.delPerformanceDir(theatre.getStage(0).getPerformance(0));
            theatre.toPrint();
            sd_1.toPrint();
        }
    }
}