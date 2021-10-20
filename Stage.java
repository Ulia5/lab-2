import java.util.Scanner;

public class Stage {                             // ���������� ������ �����
	private String nameSt;                       // �������� �����
	private int hallCapacity = 0;                // ����������� ����
	//private int numberOfPerformances = 0;      // ���������� ����������
	//private Performance* performances[50];     // ������ ����������

	public Stage() {                             // ����������� �����
		this.nameSt = toWriteName();
		this.hallCapacity = toWriteCapacity();
		System.out.println();
	}

	public Stage(String name, int capacity) {    // ����������� � ����������
		this.nameSt = name;
		this.hallCapacity = capacity;
	}

	public String getNameSt() {                  // ����������� �������� �����
		return nameSt;
	}

	public int getHallCapacity() {               // ����������� ����������� ����
		return hallCapacity;
	}

	public void toPrint() {                      // ����� ���������� � �����
		if (!getNameSt().isEmpty() && getHallCapacity() != 0) {
			System.out.print("��������: ");
			System.out.println(getNameSt());
			System.out.print("����������� ����: ");
			System.out.println(getHallCapacity());
			System.out.println();
		}
	}

	private String toWriteName() {                         // ���� �������� �����;
		System.out.print("�������� �����: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                           // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteCapacity() {                        // ���� ����������� ����
		System.out.print("����������� ����: ");
		Scanner console = new Scanner(System.in);
		int capacity = console.nextInt();
		console.nextLine();
		while (capacity < 0) {                              // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			capacity = console.nextInt();
			console.nextLine();
		}
		return capacity;
	}
}