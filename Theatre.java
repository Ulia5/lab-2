import java.util.Scanner;

public class Theatre {
	private int numberOfStages = 0;               	// ���������� ����
	private Stage [] stages = new Stage[5];       	// �����
	private int numberOfActors = 0;               	// ���������� �������
	private int numberOfStageDirectors = 0;       	// ���������� ���������� ������������� ������
	private String nameTh;                        	// �������� ������
	private int yearOfFoundation = 0;             	// ��� ���������
	private static int allActors = 0;				// ����� ���-�� ������� �� ���� �������
	private static int allStageDirectors = 0;	  	// ����� ���-�� ���������� �� ���� �������


	public Theatre()
	{   // ����������� ������
		this.nameTh = toWriteName();
		this.yearOfFoundation = toWriteYear();
		this.numberOfStages = toWriteNumberOfStages();
		this.stages = toWriteStages();
		System.out.println();
	}

	public Theatre(String nameTh, int yearOfFoundation, int numberOfStages, Stage stages[])
	{   // ����������� � ����������
		this.nameTh = nameTh;
		this.yearOfFoundation = yearOfFoundation;
		this.numberOfStages = numberOfStages;
		this.stages = stages;
	}

	public String getNameTh()
	{   // ����������� �������� ������
		return nameTh;
	}

	public int getYearOfFoundation()
	{   // ����������� ���� ��������� ������
		return yearOfFoundation;
	}

	public int getNumberOfStages()
	{   // ����������� ���� ��������� ������
		return numberOfStages;
	}

	public Stage getStage(int num)
	{	// ����������� �����
		return stages[num];
	}

	public int getNumberOfStageDirectors()
	{	// ����������� �����
		return numberOfStageDirectors;
	}

	public int getNumberOfActors()
	{	// ����������� �����
		return numberOfActors;
	}

	public void toPrint()
	{	// ����� ���������� � ������
		if (!getNameTh().isEmpty() && getYearOfFoundation() != 0) {
			System.out.print("��������: ");
			System.out.println(getNameTh());
			System.out.print("��� ���������: ");
			System.out.println(getYearOfFoundation());
			System.out.print("���������� ����: ");
			System.out.println(getNumberOfStages());
			System.out.println();
			int count = 0;
		    for (int i = 0; i < getNumberOfStages(); i++) {
				System.out.println("\t����� �" + (i + 1) + ':');
				getStage(i).toPrint();
				count += getStage(i).getNumberOfPerformances();
			}
			System.out.println();
		}

	}

	public void addStage()
	{ 	// ���������� ����� � �����
		if(getNumberOfStages() < 5) { 
			stages[getNumberOfStages()] = new Stage();
			increasingNumberOfStages();
		}
		else 
			System.out.println("����������� ���������� �������� ���-�� ����: 5!");
		System.out.println();
	}

	public void addStage(int count, Stage stage[])
	{ 	// ���������� ����� � �����
		if(getNumberOfStages() < 5) {
			for(int i = 0; i < count; i++) {
				stages[getNumberOfStages()] = stage[i];
				increasingNumberOfStages();
			}
		}
		else 
			System.out.println("����������� ���������� �������� ���-�� ����: 5!");
	}

	public void delStage(int numStage)
	{	// �������� �����
		if (numStage >= 0 && numStage < getNumberOfStages()) {
		for (int i = numStage; i < getNumberOfStages() - 1; i++) {
			stages[i] = stages[i + 1];
		}
		decreasingNumberOfStages();
	}
	else
		System.out.println("����� ����� ������ ���� � ���������� �� 0 ��" + (numberOfStages - 1) + " (�������).");
	}

	private String toWriteName()
	{   // ���� �������� ������
		System.out.print("�������� ������: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                   // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteYear()
	{   // ���� ���� ��������� ������
		System.out.print("��� ���������: ");
		YearOfFoundation year = new YearOfFoundation();
		return year.year;
	}

	private int toWriteNumberOfStages()
	{   // ���� ���������� ����
		int number;
		System.out.print("���������� ����: ");
		Scanner console = new Scanner(System.in);
		number = console.nextInt();
		console.nextLine();
		while (number < 0 || number > 5) {         // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			number = console.nextInt();
			console.nextLine();
		}
		return number;
	}

	private Stage[] toWriteStages()
	{   // ���� ���������� � ������ ������
		Stage stages[] = new Stage[getNumberOfStages()];
		for (int i = 0; i < getNumberOfStages(); i++) {
			stages[i] = new Stage();
		}
		return stages;
	}

	private void increasingNumberOfStages()
	{   // ���������� ���-�� ����
		numberOfStages++;
	}

	public void decreasingNumberOfStages()
	{   // ���������� ����� ����
		numberOfStages--;
	}

	public void increasingNumberOfActors()
	{   // ���������� ���-�� �������
		numberOfActors++;
	}

	public void increasingNumberOfStageDirectors()
	{   // ���������� ���-�� ����������
		numberOfStageDirectors++;
	}

	public static void countAllAct(Theatre th)
	{	// ������� ������ ���-�� ������� �� ���� �������
		allActors += th.getNumberOfActors();
	}

	public static int getAllAct()
	{	// ����������� ������ ���-�� ������� � �������
		return allActors;
	}

	public static void countAllDir(Theatre th)
	{	// ������� ������ ���-�� ���������� �� ���� �������
		allStageDirectors += th.getNumberOfStageDirectors();
	}

	public static int getAllDir()
	{	// ����������� ������ ���-�� ���������� � �������
		return  allStageDirectors;
	}
}