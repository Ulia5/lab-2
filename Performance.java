import java.util.Scanner;

public class Performance {
	private String namePerf;                   // �������� ����������
	private int perfomanceTime = 0;            // ����� ���������� (� �������)
	private int ageRestrictions = 0;           // ��� ��������
	//private int numberOfActors = 0;          // ���������� ������� � ����������
	//private int numberOfStageDirectors = 0;  // ���������� ���������� ������������� ������ � ����������

	public Performance() {                                 // ����������� ����������
		this.namePerf = toWriteName();
		this.perfomanceTime = toWritePerformanceTime();
		this.ageRestrictions = toWriteAgeRestrictions();
		System.out.println();
	}

	public Performance(String name, int time, int age) {   // ����������� � ����������
		this.namePerf = name;
		this.perfomanceTime = time;
		this.ageRestrictions = age;
	}

	public String getNamePerf() {                          // ����������� �������� ����������
		return namePerf;
	}

	public int getPerformanceTime() {                      // ����������� ������� ���������� 
		return perfomanceTime;
	}

	public int getAgeRegistration() {                      // ����������� ���� �������� ����������
		return ageRestrictions;
	}

	public void toPrint() {                                // ����� ���������� � ����������
		if (!getNamePerf().isEmpty() && getPerformanceTime() != 0 && getAgeRegistration() != 0) {
		System.out.print("\t\t������������ ����������: ");
		System.out.println(getNamePerf());
		System.out.print("\t\t����� ���������� (� �������): ");
		System.out.println(getPerformanceTime());
		System.out.print("\t\t��� ��������: ");
		System.out.println(getAgeRegistration());
		/*System.out.print("������� � ����������: ");
		System.out.println(getNumberOfActors());
		System.out.print("���������� ������������� ������ � ����������: ");
		System.out.println(getNumberOfStageDirectors());*/
		}
		else
			System.out.println("���������� ��������� ���������!");
		System.out.println();
	}

	private String toWriteName() {                         // ���� �������� ����������
		System.out.print("\t\t�������� ����������: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                           // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWritePerformanceTime() {                 // ���� ������� ���������� 
		System.out.print("\t\t����� ���������� (� �������): ");
		Scanner console = new Scanner(System.in);
		int performanceTime = console.nextInt();
		console.nextLine();
		while (performanceTime < 0) {                      // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			performanceTime = console.nextInt();
			console.nextLine();
		}
		return performanceTime;
	}

	private int toWriteAgeRestrictions() {                 // ���� ���� ��������
		System.out.print("\t\t��� ��������: ");
		Scanner console = new Scanner(System.in);
		int performanceTime = console.nextInt();
		console.nextLine();
		while (performanceTime < 0) {                      // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			performanceTime = console.nextInt();
			console.nextLine();
		}
		return performanceTime;
	}
}
