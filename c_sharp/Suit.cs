using System;

public class Suit : Costume
{
    private String type;

    public Suit(String color, int size, int price, String type) : base (color, size, price) {
        this.type = type;
    }


    public override void print()
    {
        base.print();
        Console.WriteLine("Тип: " + type);
    }
}