import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("����� � ���������", 200, 1999);
		stages_1[0] = new Stage("�������", 600, 2, performance);
		Theatre theatre_1 = new Theatre("�������������", 1990, 1, stages_1);
		Theatre theatre_2 = new Theatre("�����������", 2000, 1, stages_1);
		Actor[] actors = new Actor[2];
		actors[0] = new Actor("������",  "��������", 65, theatre_1);
		actors[1] = new Actor("������",  "�������", 35, theatre_2);
		System.out.println("������� �1\n");
		try
		{
			Scanner console = new Scanner(System.in);
			performance[1] = new Performance(console.nextLine());
		}
		catch (IllegalArgumentException ex)
		{
			System.out.println(ex.getMessage());
		}
	}
}