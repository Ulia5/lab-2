import java.util.Scanner;

public class Stage {                                              // Объявление класса Сцена
	private String nameSt;                                        // Название сцены
	private int hallCapacity = 0;                                 // Вместимость зала
	private int numberOfPerformances = 0;                         // Количество постановок
	private Performance performances[] = new Performance[10];     // Список постановок

	public Stage() {                                              // Конструктор Сцены
		this.nameSt = toWriteName();
		this.hallCapacity = toWriteCapacity();
		this.numberOfPerformances = toWriteNumberOfPerformance();
		this.performances = toWritePerformance();
		System.out.println();
	}

	public Stage(String name, int capacity, int numberPerf, Performance performances[]) {    // Конструктор с параметром
		this.nameSt = name;
		this.hallCapacity = capacity;
		this.numberOfPerformances = numberPerf;
		this.performances = performances;
	}

	public String getNameSt() {                  // Возвращение названия Сцены
		return nameSt;
	}

	public int getHallCapacity() {               // Возвращение вместимости зала
		return hallCapacity;
	}

	public int getNumberOfPerformances() {       // Возвращение кол-ва постановок
		return numberOfPerformances;
	}

	public Performance getPerformance(int num) { // Возвращение Постановки
		return performances[num];
	}

	public void toPrint() {                      // Вывод информации о Сцене
		if (!getNameSt().isEmpty() && getHallCapacity() != 0) {
			System.out.print("\tНазвание: ");
			System.out.println(getNameSt());
			System.out.print("\tВместимость зала: ");
			System.out.println(getHallCapacity());
			System.out.print("\tПостановок на сцене: ");
			System.out.println(getNumberOfPerformances());
			System.out.println();
			for (int i = 0; i < getNumberOfPerformances(); i++) {
				System.out.println("\tПостановка №" + (i + 1) + ':');
				getPerformance(i).toPrint();
			}
		}
		else
			System.out.println("Необходимо заполнить структуру!");
		System.out.println();
	}

	public void addPerformance() {                                      // Добавление постановки в Сцену
		if(getNumberOfPerformances() < 10) { 
			performances[getNumberOfPerformances()] = new Performance();
			increasingNumberOfPerformances();
		}
		else 
			System.out.println("Максимально допустимое значение кол-ва Постановок: 10!");
		System.out.println();
	}

	public void addPerformance(int count, Performance performance[]) {  //  Добавление постановки в Сцену
		if(getNumberOfPerformances() < 10) {
			for(int i = 0; i < count; i++) {
				performances[getNumberOfPerformances()] = performance[i];
				increasingNumberOfPerformances();
			}
		}
		else 
			System.out.println("Максимально допустимое значение кол-ва Постановок: 10!");
	}

	public void delPerformance(int numPerformance) {
		if (numPerformance >= 0 && numPerformance < getNumberOfPerformances()) {
		for (int i = numPerformance; i < getNumberOfPerformances() - 1; i++) {
			performances[i] = performances[i + 1];
		}
		decreaseNumberOfPerformances();
	}
	else
		System.out.println("Номер постановки должен быть в промежутке от 0 до" + (getNumberOfPerformances() - 1) + " (включая).");
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
		System.out.print("\tВместимость зала: ");
		Scanner console = new Scanner(System.in);
		int capacity = console.nextInt();
		console.nextLine();
		while (capacity < 0) {                             // Защита от неверного ввода
			System.out.println("\tНеверный формат ввода!");
			capacity = console.nextInt();
			console.nextLine();
		}
		return capacity;
	}

	private int toWriteNumberOfPerformance() {             // Ввод кол-ва Постановок
		System.out.print("\tВместимость зала: ");
		Scanner console = new Scanner(System.in);
		int numberOfPerformances = console.nextInt();
		console.nextLine();
		while (numberOfPerformances < 0 || numberOfPerformances > 50) { // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			numberOfPerformances = console.nextInt();
			console.nextLine();
		}
		return numberOfPerformances;
	}

	private Performance[] toWritePerformance() {      // Ввод Постановок
		Performance performances[] = new Performance[getNumberOfPerformances()];
		for (int i = 0; i < getNumberOfPerformances(); i++) {
			performances[i] = new Performance();
		}
		return performances;
	}

	private void increasingNumberOfPerformances() {   // Увеличение кол-ва Постановок
		numberOfPerformances++;
	}

	private void decreaseNumberOfPerformances() {     // Уменьшение числа Постановок
		numberOfPerformances--;
	}
}
