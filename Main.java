import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("����� � ���������", 200, 1999);
		performance[1] = new Performance("������ � ������", 180, 1990);
		stages_1[0] = new Stage("�������", 600, 2, performance);
		Theatre theatre_1 = new Theatre("�������������", 1990, 1, stages_1);
		Theatre theatre_2 = new Theatre("�����������", 2000, 1, stages_1);
		Actor[] actors = new Actor[2];
		actors[0] = new Actor("������",  "��������", 65, theatre_1);
		actors[0] = new Actor("������",  "�������", 35, theatre_2);
		System.out.println("������� �1\n");
		System.out.println("����������� �� ����� �����������:");
		actors[0].toPrint();
		System.out.println("����������� � 1 ����������:");
		Actor actor = new Actor(theatre_1);
		System.out.println("����������� ��� ����������:");
		Actor actor1 = new Actor();
		System.out.println("������������� ������� ������������� � ����� ����������:");
		Actor[] actors1 = new Actor [2];
		for(int i = 0; i < 2; i++)
			actors1[i] = new Actor(theatre_2);
	}
}