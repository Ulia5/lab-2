using System;
using System.Text;

namespace c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Theatre theatre_1 = new Theatre();
            Theatre theatre_2 = new Theatre("Драматический", 1990);
            theatre_1.toPrint();
            theatre_2.toPrint();
        }
    }
}