import java.util.Scanner;

public class StageDirector {
	private String nameDir;     // Имя Работнико постановочной группы
	private String surnameDir;  // Фамилия Работников постановочной группы
	private int ageDir = 0;     // Возраст Работников постановочной группы
	private int roles = 0;      // Количество Работников постановочной группы
	private Theatre jobPlace;   // Место работы
	private Performance performanceDir[] = new Performance[50]; // Постановки, созданные при участии  данного Работников

	public StageDirector(Theatre theatre) {    // Конструктор Работников постановочной группы
		this.nameDir = toWriteNameDir();
		this.surnameDir = toWriteSurnameDir();
		this.ageDir = toWriteAgeDir();
		this.jobPlace = theatre;
		System.out.println();
	}

	public StageDirector(String name, String surname, int age, Theatre theatre) { // Конструктор Работников постановочной
																		  // группы с параметрами
		this.nameDir = name;
		this.surnameDir = surname;
		this.ageDir = age;
		this.jobPlace = theatre;
	}

	public String getNameDir() {     // Возвращение имени Работников
		return nameDir;
	}

	public String getSurnameDir() {  // Возвращение фамилии Работников
		return surnameDir;
	}

	public int getAgeDir() {         // Возвращение возраста Работника
		return ageDir;
	}

	public Theatre getJobPlace() {   // Возвращение места работы Работнико
		return jobPlace;
	}

	public Performance getPerformanceDir(int num) {  // Возвращение постановки с участ. Работников
		return performanceDir[num];
	}

	public int getRoles() { // Возвращение кол-ва работ
		return roles;
	}

	public void toPrint() {  // Вывод информации о Работнике
		if(!getNameDir().isEmpty() && !getSurnameDir().isEmpty() && getAgeDir() != 0) {
			System.out.print("Имя и фамилия: ");
			System.out.println(getNameDir() + ' ' + getSurnameDir());
			System.out.print("Возраст: ");
			System.out.println(getAgeDir());
			System.out.print("Место работы: ");
			System.out.println(getJobPlace().getNameTh());
			System.out.print("Количество работ: ");
			System.out.println(getRoles());
			if (getRoles() > 0) {
				System.out.println("Такие постановки как: ");
				for (int i = 0; i < getRoles(); i++)
					System.out.println((i + 1) + ") " + getPerformanceDir(i).getNamePerf());
			}
			System.out.println();
		}
	}

	public void addPerformanceDir(Performance performance) { // Добавление Постановки в список работ
		performanceDir[getRoles()] = performance;
		performanceDir[getRoles()].addStageDirector();
		addRoles();
	}

	public void delPerformanceDir(Performance performance) { // Удаление Постановки из списка работ
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
		System.out.println("Таких работ не найдено!");
	}

	private String toWriteNameDir() {                   // Ввод имени Работника
		System.out.print("Имя работника постановочной группы: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                        // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private String toWriteSurnameDir() {                // Ввод фамилии Работника
		System.out.print("Фамилия работника постановочной группы: ");
		Scanner console = new Scanner(System.in);
		String surname = console.nextLine();
		while (surname.isEmpty()) {                     // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			surname = console.nextLine();
		}
		return surname;
	}

	private int toWriteAgeDir() {                       // Ввод возраста Работника
		System.out.print("Возраст работника постановочной группы: ");
		Scanner console = new Scanner(System.in);
		int age = console.nextInt();
		console.nextLine();
		while (age < 0) {                            // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			age = console.nextInt();
			console.nextLine();
		}
		return age;
	}

	private void addRoles() { // Добавление работы
		roles++;
	}

	private void delRoles() { // Удаление работы
		roles--;
	}
}