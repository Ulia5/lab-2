using System;

public abstract class TheatricalThings
{
    public void thingInf()
    {
        print();
        Console.WriteLine("Цена: " + getPrice() + "\n");
    }
    public abstract void print();
    public abstract int getPrice();
}
 