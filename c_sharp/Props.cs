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

    public override void print()
    {
        Console.WriteLine("Уровень опасности: " + hazardLevel);
        Console.WriteLine("Срок службы: " + serviceLife);
        Console.WriteLine("Период использования: " + periodOfUse);
        if (status)
        {
            Console.WriteLine("Статус: используется");
        }
        else
        {
            Console.WriteLine("Статус: списано");
        }
    }

    public override int getPrice()
    {
        return price;
    }
}

