import java.util.Scanner;

public class Theatre {
	//private int numberOfStages = 0;             // Количество сцен
	//Stage stages[5];                            // Сцены
	//private int numberOfActors = 0;             // Количество актеров
	//private int numberOfStageDirectors = 0;     // Количество работников постановочной группы
	private String nameTh;                        // Название театра
	private int yearOfFoundation = 0;             // Год основания

	public Theatre() {                            // Конструктор Театра
		this.nameTh = toWriteName();
		this.yearOfFoundation = toWriteYear();
	}

	public Theatre(String name, int year) {       // Конструктор с параметром
		this.nameTh = name;
		this.yearOfFoundation = year;
	}

	public String getNameTh() {                   // Возвращение названия Театра
		return nameTh;
	}

	public int getYearOfFoundation() {             // Возвращения года основания Театра
		return yearOfFoundation;
	}

	public void toPrint() {                        // Вывод информации о Театре
		if (!getNameTh().isEmpty() && getYearOfFoundation() != 0) {
			System.out.print("Название: ");
			System.out.println(getNameTh());
			System.out.print("Год основания: ");
			System.out.println(getYearOfFoundation());
			System.out.println();
		}
	}

	private String toWriteName() {                 // Ввод названия Театра
		Scanner console = new Scanner(System.in);
		System.out.print("Название театра: ");
		String name = console.nextLine();
		while (name.isEmpty()) {                   // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteYear() {                    // Ввод года основания Театра
		int year;
		Scanner console = new Scanner(System.in);
		System.out.print("Год основания: ");
		year = console.nextInt();
		while (year < 1740 || year > 2021) {       // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			year = console.nextInt();
		}
		return year;
	}
}