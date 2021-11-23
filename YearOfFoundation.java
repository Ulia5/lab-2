import java.util.Scanner;
import java.util.Date;

public class YearOfFoundation {
    public int year;

    public YearOfFoundation()
    {
        Date dt = new Date();
        Scanner console = new Scanner(System.in);
        year = console.nextInt();
        console.nextLine();
        while (year < 1740 || year > (1900 + dt.getYear())) {       // Защита от неверного ввода
            System.out.println("Неверный формат ввода!");
            year = console.nextInt();
            console.nextLine();
        }
    }
}
