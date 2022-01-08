import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws CloneNotSupportedException {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("����� � ���������", 200, 1999);
		performance[1] = new Performance("������� �����", 250, 1990);
		stages_1[0] = new Stage("�������", 600, 2, performance);
		Theatre [][] theatre = new Theatre [2][1];
		theatre[0][0] = new Theatre("�������������", 1990, 1, stages_1);
		theatre[1][0] = new Theatre("�����������", 2000, 1, stages_1);
		Actor[] actors = new Actor[2];
		actors[0] = new Actor("������",  "��������", 65, theatre[0][0]);
		actors[1] = new Actor("������",  "�������", 35, theatre[1][0]);
		System.out.println("������� �1\n");
		Suit newSuit = new Suit("������",40,5000, "����");
		newSuit.printCostume();
		System.out.println("������� �2\n");
		Sword newSword = new Sword(5, 10, 10000);
		newSword.printProps();
		newSword.changePeriodOfUse(2);
		newSword.printProps();
		newSword.changePeriodOfUse(9);
		newSword.printProps();
		System.out.println("������� �3\n");
		System.out.println("����� ��������� ��������� � ��������: " + (newSuit.getPrice() + newSword.getPrice()));
		System.out.println("������� �4\n");
		Actor actor = new Actor("������",  "�����", 65, theatre[1][0]);
		actor.addPerformanceAct(performance[0]);
		Actor clonedActor = actor.clone();
		System.out.println("��������:");
		actor.toPrint();
		System.out.println("����:");
		clonedActor.toPrint();
		clonedActor.addPerformanceAct(performance[1]);
		System.out.println("�������� ����� ���������:");
		actor.toPrint();
		System.out.println("���� ����� ���������:");
		clonedActor.toPrint();
	}
}