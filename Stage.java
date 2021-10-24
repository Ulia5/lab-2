import java.util.Scanner;

public class Stage {                                              // ���������� ������ �����
	private String nameSt;                                        // �������� �����
	private int hallCapacity = 0;                                 // ����������� ����
	private int numberOfPerformances = 0;                         // ���������� ����������
	private Performance performances[] = new Performance[10];     // ������ ����������

	public Stage() {                                              // ����������� �����
		this.nameSt = toWriteName();
		this.hallCapacity = toWriteCapacity();
		this.numberOfPerformances = toWriteNumberOfPerformance();
		this.performances = toWritePerformance();
		System.out.println();
	}

	public Stage(String name, int capacity, int numberPerf, Performance performances[]) {    // ����������� � ����������
		this.nameSt = name;
		this.hallCapacity = capacity;
		this.numberOfPerformances = numberPerf;
		this.performances = performances;
	}

	public String getNameSt() {                  // ����������� �������� �����
		return nameSt;
	}

	public int getHallCapacity() {               // ����������� ����������� ����
		return hallCapacity;
	}

	public int getNumberOfPerformances() {       // ����������� ���-�� ����������
		return numberOfPerformances;
	}

	public Performance getPerformance(int num) { // ����������� ����������
		return performances[num];
	}

	public void toPrint() {                      // ����� ���������� � �����
		if (!getNameSt().isEmpty() && getHallCapacity() != 0) {
			System.out.print("\t��������: ");
			System.out.println(getNameSt());
			System.out.print("\t����������� ����: ");
			System.out.println(getHallCapacity());
			System.out.print("\t���������� �� �����: ");
			System.out.println(getNumberOfPerformances());
			System.out.println();
			for (int i = 0; i < getNumberOfPerformances(); i++) {
				System.out.println("\t���������� �" + (i + 1) + ':');
				getPerformance(i).toPrint();
			}
		}
		else
			System.out.println("���������� ��������� ���������!");
		System.out.println();
	}

	public void addPerformance() {                                      // ���������� ���������� � �����
		if(getNumberOfPerformances() < 10) { 
			performances[getNumberOfPerformances()] = new Performance();
			increasingNumberOfPerformances();
		}
		else 
			System.out.println("����������� ���������� �������� ���-�� ����������: 10!");
		System.out.println();
	}

	public void addPerformance(int count, Performance performance[]) {  //  ���������� ���������� � �����
		if(getNumberOfPerformances() < 10) {
			for(int i = 0; i < count; i++) {
				performances[getNumberOfPerformances()] = performance[i];
				increasingNumberOfPerformances();
			}
		}
		else 
			System.out.println("����������� ���������� �������� ���-�� ����������: 10!");
	}

	public void delPerformance(int numPerformance) {
		if (numPerformance >= 0 && numPerformance < getNumberOfPerformances()) {
		for (int i = numPerformance; i < getNumberOfPerformances() - 1; i++) {
			performances[i] = performances[i + 1];
		}
		decreaseNumberOfPerformances();
	}
	else
		System.out.println("����� ���������� ������ ���� � ���������� �� 0 ��" + (getNumberOfPerformances() - 1) + " (�������).");
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
		System.out.print("\t����������� ����: ");
		Scanner console = new Scanner(System.in);
		int capacity = console.nextInt();
		console.nextLine();
		while (capacity < 0) {                             // ������ �� ��������� �����
			System.out.println("\t�������� ������ �����!");
			capacity = console.nextInt();
			console.nextLine();
		}
		return capacity;
	}

	private int toWriteNumberOfPerformance() {             // ���� ���-�� ����������
		System.out.print("\t����������� ����: ");
		Scanner console = new Scanner(System.in);
		int numberOfPerformances = console.nextInt();
		console.nextLine();
		while (numberOfPerformances < 0 || numberOfPerformances > 50) { // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			numberOfPerformances = console.nextInt();
			console.nextLine();
		}
		return numberOfPerformances;
	}

	private Performance[] toWritePerformance() {      // ���� ����������
		Performance performances[] = new Performance[getNumberOfPerformances()];
		for (int i = 0; i < getNumberOfPerformances(); i++) {
			performances[i] = new Performance();
		}
		return performances;
	}

	private void increasingNumberOfPerformances() {   // ���������� ���-�� ����������
		numberOfPerformances++;
	}

	private void decreaseNumberOfPerformances() {     // ���������� ����� ����������
		numberOfPerformances--;
	}
}
