using System;

public class Costume : TheatricalThings
{
    protected String color;
    protected int size;
    protected int price;


    public Costume()
    {
        this.color = "Белый";
        this.size = 46;
        this.price = 5000;
    }

    public Costume(String color, int size, int price)
    {
        this.color = color;
        this.size = size;
        this.price = price;
    }

    public virtual void printCostume()
    {
        Console.WriteLine("Цвет: " + color);
        Console.WriteLine("Размер: " + size);
        Console.WriteLine("Цена: " + price);
    }

    public int getPrice()
    {
        return price;
    }
}

