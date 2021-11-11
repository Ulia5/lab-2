import java.util.Scanner;

public class Performance {
	private String namePerf;                   // Название Постановки
	private int perfomanceTime = 0;            // Время Постановки (в минутах)
	private int ageRestrictions = 0;           // Год премьеры
	//private int numberOfActors = 0;          // Количество актеров в Постановке
	//private int numberOfStageDirectors = 0;  // Количество работников Постановочной группы в постановке

	public Performance() {                                 // Конструктор Постановки
		this.namePerf = toWriteName();
		this.perfomanceTime = toWritePerformanceTime();
		this.ageRestrictions = toWriteAgeRestrictions();
		System.out.println();
	}

	public Performance(String name, int time, int age) {   // Конструктор с параметром
		this.namePerf = name;
		this.perfomanceTime = time;
		this.ageRestrictions = age;
	}

	public String getNamePerf() {                          // Возвращение названия Постановки
		return namePerf;
	}

	public int getPerformanceTime() {                      // Возвращение времени Постановки 
		return perfomanceTime;
	}

	public int getAgeRegistration() {                      // Возвраещние года премьеры Постановки
		return ageRestrictions;
	}

	public void toPrint() {                                // Вывод информации о постановке
		if (!getNamePerf().isEmpty() && getPerformanceTime() != 0 && getAgeRegistration() != 0) {
		System.out.print("\t\tНаименование постановки: ");
		System.out.println(getNamePerf());
		System.out.print("\t\tВремя постановки (в минутах): ");
		System.out.println(getPerformanceTime());
		System.out.print("\t\tГод премьеры: ");
		System.out.println(getAgeRegistration());
		/*System.out.print("Актеров в постановке: ");
		System.out.println(getNumberOfActors());
		System.out.print("Работников постановочной группы в постановке: ");
		System.out.println(getNumberOfStageDirectors());*/
		}
		else
			System.out.println("Необходимо заполнить структуру!");
		System.out.println();
	}

	private String toWriteName() {                         // Ввод названия Постановки
		System.out.print("\t\tНазвание Постановки: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                           // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWritePerformanceTime() {                 // Ввод времени Постановки 
		System.out.print("\t\tВремя постановки (в минутах): ");
		Scanner console = new Scanner(System.in);
		int performanceTime = console.nextInt();
		console.nextLine();
		while (performanceTime < 0) {                      // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			performanceTime = console.nextInt();
			console.nextLine();
		}
		return performanceTime;
	}

	private int toWriteAgeRestrictions() {                 // Ввод года премьеры
		System.out.print("\t\tГод премьеры: ");
		Scanner console = new Scanner(System.in);
		int performanceTime = console.nextInt();
		console.nextLine();
		while (performanceTime < 0) {                      // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			performanceTime = console.nextInt();
			console.nextLine();
		}
		return performanceTime;
	}
}
