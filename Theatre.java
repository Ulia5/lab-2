import java.util.Scanner;

public class Theatre {
	//private int numberOfStages = 0;             // ���������� ����
	//Stage stages[5];                            // �����
	//private int numberOfActors = 0;             // ���������� �������
	//private int numberOfStageDirectors = 0;     // ���������� ���������� ������������� ������
	private String nameTh;                        // �������� ������
	private int yearOfFoundation = 0;             // ��� ���������

	public Theatre() {                            // ����������� ������
		this.nameTh = toWriteName();
		this.yearOfFoundation = toWriteYear();
	}

	public Theatre(String name, int year) {       // ����������� � ����������
		this.nameTh = name;
		this.yearOfFoundation = year;
	}

	public String getNameTh() {                   // ����������� �������� ������
		return nameTh;
	}

	public int getYearOfFoundation() {             // ����������� ���� ��������� ������
		return yearOfFoundation;
	}

	public void toPrint() {                        // ����� ���������� � ������
		if (!getNameTh().isEmpty() && getYearOfFoundation() != 0) {
			System.out.print("��������: ");
			System.out.println(getNameTh());
			System.out.print("��� ���������: ");
			System.out.println(getYearOfFoundation());
			System.out.println();
		}
	}

	private String toWriteName() {                 // ���� �������� ������
		Scanner console = new Scanner(System.in);
		System.out.print("�������� ������: ");
		String name = console.nextLine();
		while (name.isEmpty()) {                   // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteYear() {                    // ���� ���� ��������� ������
		int year;
		Scanner console = new Scanner(System.in);
		System.out.print("��� ���������: ");
		year = console.nextInt();
		while (year < 1740 || year > 2021) {       // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			year = console.nextInt();
		}
		return year;
	}
}