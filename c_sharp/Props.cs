using System;

public abstract class Props : TheatricalThings
{
    protected int hazardLevel;
    protected int serviceLife;
    protected int periodOfUse;
    protected int price;
    protected bool status;

    protected void securityCheck()
    {
        if (periodOfUse >= serviceLife && hazardLevel > 2)
        {
            status = false;
        }
    }

    public void printProps()
    {
        Console.WriteLine("Уровень опасности: " + hazardLevel);
        Console.WriteLine("Срок службы: " + serviceLife);
        Console.WriteLine("Период использования: " + periodOfUse);
        Console.WriteLine("Цена: " + price);
        if (status)
        {
            Console.WriteLine("Статус: используется\n");
        }
        else
        {
            Console.WriteLine("Статус: списано\n");
        }
    }

    public int getPrice()
    {
        return price;
    }
}

