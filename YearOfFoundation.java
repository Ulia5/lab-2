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
        while (year < 1740 || year > (1900 + dt.getYear())) {       // ������ �� ��������� �����
            System.out.println("�������� ������ �����!");
            year = console.nextInt();
            console.nextLine();
        }
    }
}
