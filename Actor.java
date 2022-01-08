import java.util.Scanner;

public class Actor implements Cloneable
{
	private String nameAct;     // Имя актера
	private String surnameAct;  // Фамилия актера
	private int ageAct = 0;     // Возраст актера
	private int roles = 0;      // Количество ролей
	private Theatre jobPlace;   // Место работы
	private Performance performanceAct[] = new Performance[50]; // Постановки с участием данного актера

	public Actor()
	{	// Конструктор без параметров
		this.nameAct = toWriteNameAct();
		this.surnameAct = toWriteSurnameAct();
		this.ageAct = toWriteAgeAct();
		this.jobPlace = toWriteTheatre();
		this.jobPlace.increasingNumberOfActors();
		System.out.println();
	}

	public Actor(Theatre theatre)
	{   // Конструктор с одним параметром
		this.nameAct = toWriteNameAct();
		this.surnameAct = toWriteSurnameAct();
		this.ageAct = toWriteAgeAct();
		this.jobPlace = theatre;
		this.jobPlace.increasingNumberOfActors();
		System.out.println();
	}

	public Actor(String name, String surname, int age, Theatre theatre)
	{ 	// Конструктор со всеми параметрами
		this.nameAct = name;
		this.surnameAct = surname;
		this.ageAct = age;
		this.jobPlace = theatre;
		this.jobPlace.increasingNumberOfActors();
	}

	public String getNameAct()
	{   // Возвращение имени Актера
		return nameAct;
	}

	public String getSurnameAct()
	{   // Возвращение фамилии Актера
		return surnameAct;
	}

	public int getAgeAct()
	{   // Возвращение возраста Актера
		return ageAct;
	}

	public Theatre getJobPlace()
	{   // Возвращение места работы Актера
		return jobPlace;
	}

	public Performance getPerformanceAct(int num)
	{   // Возвращение постановки с участ. Актера
		return performanceAct[num];
	}

	public int getRoles()
	{   // Возвращение кол-ва ролей
		return roles;
	}

	public void toPrint()
	{	// Вывод информации об Актере
		if(!getNameAct().isEmpty() && !getSurnameAct().isEmpty() && getAgeAct() != 0)
		{
			System.out.print("Имя и фамилия: ");
			System.out.println(getNameAct() + ' ' + getSurnameAct());
			System.out.print("Возраст: ");
			System.out.println(getAgeAct());
			System.out.print("Место работы: ");
			System.out.println(getJobPlace().getNameTh());
			System.out.print("Количество ролей: ");
			System.out.println(getRoles());
			if (getRoles() > 0)
			{
				System.out.println("В таких постановках как: ");
				for (int i = 0; i < getRoles(); i++)
					System.out.println((i + 1) + ") " + getPerformanceAct(i).getNamePerf());
			}
			System.out.println();
		}
	}

	public void addPerformanceAct(Performance performance)
	{   // Добавление Постановки в список ролей
		performanceAct[getRoles()] = performance;
		performanceAct[getRoles()].addActor();
		addRoles();
	}

	public void delPerformanceAct(Performance performance)
	{ 	// Удаление Постановки из списка ролей
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
			System.out.println("Таких постановок не найдено!");
	}

	private String toWriteNameAct()
	{   // Ввод имени Актера
		System.out.print("Имя актера: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty())
		{   // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private String toWriteSurnameAct()
	{   // Ввод фамилии Актера
		System.out.print("Фамилия актера: ");
		Scanner console = new Scanner(System.in);
		String surname = console.nextLine();
		while (surname.isEmpty())
		{   // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			surname = console.nextLine();
		}
		return surname;
	}

	private int toWriteAgeAct()
	{   // Ввод возраста Актера
		System.out.print("Возраст актера: ");
		Scanner console = new Scanner(System.in);
		int age = console.nextInt();
		console.nextLine();
		while (age < 0)
		{ 	// Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			age = console.nextInt();
			console.nextLine();
		}
		return age;
	}

	private Theatre toWriteTheatre()
	{	// Ввод театра
		Theatre theatre = new Theatre();
		return theatre;
	}

	private void addRoles()
	{   // Добавление роли
		roles++;
	}

	private void delRoles()
	{   // Удаление роли
		roles--;
	}

	@Override
	public Actor clone() throws CloneNotSupportedException {
		Actor clone = (Actor) super.clone();
		clone.performanceAct = (Performance[]) performanceAct.clone();
		return clone;
	}
}