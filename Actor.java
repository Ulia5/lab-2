import java.util.Scanner;

public class Actor implements Cloneable
{
	private String nameAct;     // ��� ������
	private String surnameAct;  // ������� ������
	private int ageAct = 0;     // ������� ������
	private int roles = 0;      // ���������� �����
	private Theatre jobPlace;   // ����� ������
	private Performance performanceAct[] = new Performance[50]; // ���������� � �������� ������� ������

	public Actor()
	{	// ����������� ��� ����������
		this.nameAct = toWriteNameAct();
		this.surnameAct = toWriteSurnameAct();
		this.ageAct = toWriteAgeAct();
		this.jobPlace = toWriteTheatre();
		this.jobPlace.increasingNumberOfActors();
		System.out.println();
	}

	public Actor(Theatre theatre)
	{   // ����������� � ����� ����������
		this.nameAct = toWriteNameAct();
		this.surnameAct = toWriteSurnameAct();
		this.ageAct = toWriteAgeAct();
		this.jobPlace = theatre;
		this.jobPlace.increasingNumberOfActors();
		System.out.println();
	}

	public Actor(String name, String surname, int age, Theatre theatre)
	{ 	// ����������� �� ����� �����������
		this.nameAct = name;
		this.surnameAct = surname;
		this.ageAct = age;
		this.jobPlace = theatre;
		this.jobPlace.increasingNumberOfActors();
	}

	public String getNameAct()
	{   // ����������� ����� ������
		return nameAct;
	}

	public String getSurnameAct()
	{   // ����������� ������� ������
		return surnameAct;
	}

	public int getAgeAct()
	{   // ����������� �������� ������
		return ageAct;
	}

	public Theatre getJobPlace()
	{   // ����������� ����� ������ ������
		return jobPlace;
	}

	public Performance getPerformanceAct(int num)
	{   // ����������� ���������� � �����. ������
		return performanceAct[num];
	}

	public int getRoles()
	{   // ����������� ���-�� �����
		return roles;
	}

	public void toPrint()
	{	// ����� ���������� �� ������
		if(!getNameAct().isEmpty() && !getSurnameAct().isEmpty() && getAgeAct() != 0)
		{
			System.out.print("��� � �������: ");
			System.out.println(getNameAct() + ' ' + getSurnameAct());
			System.out.print("�������: ");
			System.out.println(getAgeAct());
			System.out.print("����� ������: ");
			System.out.println(getJobPlace().getNameTh());
			System.out.print("���������� �����: ");
			System.out.println(getRoles());
			if (getRoles() > 0)
			{
				System.out.println("� ����� ����������� ���: ");
				for (int i = 0; i < getRoles(); i++)
					System.out.println((i + 1) + ") " + getPerformanceAct(i).getNamePerf());
			}
			System.out.println();
		}
	}

	public void addPerformanceAct(Performance performance)
	{   // ���������� ���������� � ������ �����
		performanceAct[getRoles()] = performance;
		performanceAct[getRoles()].addActor();
		addRoles();
	}

	public void delPerformanceAct(Performance performance)
	{ 	// �������� ���������� �� ������ �����
		boolean flag = false;
		int numPerf = 0;
		for (int i = 0; i < getRoles(); i++)
			if (performanceAct[i].getNamePerf() == performance.getNamePerf())
			{
				flag = true;
				numPerf = i;
			}
		if (flag)
		{
			for (int i = numPerf; i < roles - 1; i++)
			{
				performanceAct[i] = performanceAct[i + 1];
			}
			performanceAct[roles - 1] = null;
			delRoles();
			performance.delActor();
		}
		else
			System.out.println("����� ���������� �� �������!");
	}

	private String toWriteNameAct()
	{   // ���� ����� ������
		System.out.print("��� ������: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty())
		{   // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			name = console.nextLine();
		}
		return name;
	}

	private String toWriteSurnameAct()
	{   // ���� ������� ������
		System.out.print("������� ������: ");
		Scanner console = new Scanner(System.in);
		String surname = console.nextLine();
		while (surname.isEmpty())
		{   // ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			surname = console.nextLine();
		}
		return surname;
	}

	private int toWriteAgeAct()
	{   // ���� �������� ������
		System.out.print("������� ������: ");
		Scanner console = new Scanner(System.in);
		int age = console.nextInt();
		console.nextLine();
		while (age < 0)
		{ 	// ������ �� ��������� �����
			System.out.println("�������� ������ �����!");
			age = console.nextInt();
			console.nextLine();
		}
		return age;
	}

	private Theatre toWriteTheatre()
	{	// ���� ������
		Theatre theatre = new Theatre();
		return theatre;
	}

	private void addRoles()
	{   // ���������� ����
		roles++;
	}

	private void delRoles()
	{   // �������� ����
		roles--;
	}

	@Override
	public Actor clone() throws CloneNotSupportedException {
		Actor clone = (Actor) super.clone();
		clone.performanceAct = (Performance[]) performanceAct.clone();
		return clone;
	}
}