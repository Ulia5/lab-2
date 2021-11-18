import java.util.Scanner;

public class StageDirector {
	private String nameDir;     // ��� ��������� ������������� ������
	private String surnameDir;  // ������� ���������� ������������� ������
	private int ageDir = 0;     // ������� ���������� ������������� ������
	private int roles = 0;      // ���������� ���������� ������������� ������
	private Theatre jobPlace;   // ����� ������
	private Performance performanceDir[] = new Performance[50]; // ����������, ��������� ��� �������  ������� ����������

	public StageDirector(Theatre theatre) {    // ����������� ���������� ������������� ������
		this.nameDir = toWriteNameDir();
		this.surnameDir = toWriteSurnameDir();
		this.ageDir = toWriteAgeDir();
		this.jobPlace = theatre;
		System.out.println();
	}

	public StageDirector(String name, String surname, int age, Theatre theatre) { // ����������� ���������� �������������
																		  // ������ � �����������
		this.nameDir = name;
		this.surnameDir = surname;
		this.ageDir = age;
		this.jobPlace = theatre;
	}

	public String getNameDir() {     // ����������� ����� ����������
		return nameDir;
	}

	public String getSurnameDir() {  // ����������� ������� ����������
		return surnameDir;
	}

	public int getAgeDir() {         // ����������� �������� ���������
		return ageDir;
	}

	public Theatre getJobPlace() {   // ����������� ����� ������ ���������
		return jobPlace;
	}

	public Performance getPerformanceDir(int num) {  // ����������� ���������� � �����. ����������
		return performanceDir[num];
	}

	public int getRoles() { // ����������� ���-�� �����
		return roles;
	}

	public void toPrint() {  // ����� ���������� � ���������
		if(!getNameDir().isEmpty() && !getSurnameDir().isEmpty() && getAgeDir() != 0) {
			System.out.print("��� � �������: ");
			System.out.println(getNameDir() + ' ' + getSurnameDir());
			System.out.print("�������: ");
			System.out.println(getAgeDir());
			System.out.print("����� ������: ");
			System.out.println(getJobPlace().getNameTh());
			System.out.print("���������� �����: ");
			System.out.println(getRoles());
			if (getRoles() > 0) {
				System.out.println("����� ���������� ���: ");
				for (int i = 0; i < getRoles(); i++)
					System.out.println((i + 1) + ") " + getPerformanceDir(i).getNamePerf());
			}
			System.out.println();
		}
	}

	public void addPerformanceDir(Performance performance) { // ���������� ���������� � ������ �����
		performanceDir[getRoles()] = performance;
		performanceDir[getRoles()].addStageDirector();
		addRoles();
	}

	public void delPerformanceDir(Performance performance) { // �������� ���������� �� ������ �����
	boolean flag = false;
	int numPerf = 0;
	for (int i = 0; i < getRoles(); i++)
		if (performanceDir[i].getNamePerf() == performance.getNamePerf()) {
			flag = true;
			numPerf = i;
		}
	if (flag) {
		for (int i = numPerf; i < roles - 1; i++) {
			performanceDir[i] = performanceDir[i + 1];
		}
		performanceDir[roles - 1] = null;
		delRoles();
		performance.delStageDirector();
	}
	else
		System.out.println("����� ����� �� �������!");
	}

	private String toWriteNameDir() {                   // ���� ����� ���������
		System.out.print("��� ��������� ������������� ������: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                        // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private String toWriteSurnameDir() {                // ���� ������� ���������
		System.out.print("������� ��������� ������������� ������: ");
		Scanner console = new Scanner(System.in);
		String surname = console.nextLine();
		while (surname.isEmpty()) {                     // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			surname = console.nextLine();
		}
		return surname;
	}

	private int toWriteAgeDir() {                       // ���� �������� ���������
		System.out.print("������� ��������� ������������� ������: ");
		Scanner console = new Scanner(System.in);
		int age = console.nextInt();
		console.nextLine();
		while (age < 0) {                            // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			age = console.nextInt();
			console.nextLine();
		}
		return age;
	}

	private void addRoles() { // ���������� ������
		roles++;
	}

	private void delRoles() { // �������� ������
		roles--;
	}
}