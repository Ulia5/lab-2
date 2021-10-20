import java.util.Scanner;

public class Stage {                             // Объявление класса Сцена
	private String nameSt;                       // Название сцены
	private int hallCapacity = 0;                // Вместимость зала
	//private int numberOfPerformances = 0;      // Количество постановок
	//private Performance* performances[50];     // Список постановок

	public Stage() {                             // Конструктор Сцены
		this.nameSt = toWriteName();
		this.hallCapacity = toWriteCapacity();
		System.out.println();
	}

	public Stage(String name, int capacity) {    // Конструктор с параметром
		this.nameSt = name;
		this.hallCapacity = capacity;
	}

	public String getNameSt() {                  // Возвращение названия Сцены
		return nameSt;
	}

	public int getHallCapacity() {               // Возвращения вместимость зала
		return hallCapacity;
	}

	public void toPrint() {                      // Вывод информации о Сцене
		if (!getNameSt().isEmpty() && getHallCapacity() != 0) {
			System.out.print("Название: ");
			System.out.println(getNameSt());
			System.out.print("Вместимость зала: ");
			System.out.println(getHallCapacity());
			System.out.println();
		}
	}

	private String toWriteName() {                         // Ввод названия Сцены;
		System.out.print("Название сцены: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                           // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteCapacity() {                        // Ввод вместимости зала
		System.out.print("Вместимость зала: ");
		Scanner console = new Scanner(System.in);
		int capacity = console.nextInt();
		console.nextLine();
		while (capacity < 0) {                              // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			capacity = console.nextInt();
			console.nextLine();
		}
		return capacity;
	}
}