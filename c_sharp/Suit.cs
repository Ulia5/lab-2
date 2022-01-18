using System;

public class Suit : Costume
{
    private String type;

    public Suit(String color, int size, int price, String type) : base (color, size, price) {
        this.type = type;
    }


    public override void printCostume()
    {
        base.printCostume();
        Console.WriteLine("Тип: " + type);
    }
}