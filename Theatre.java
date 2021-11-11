import java.util.Scanner;

public class Theatre {
	private int numberOfStages = 0;               // Количество сцен
	private Stage [] stages = new Stage[5];       // Сцены
	//private int numberOfActors = 0;             // Количество актеров
	//private int numberOfStageDirectors = 0;     // Количество работников постановочной группы
	private String nameTh;                        // Название театра
	private int yearOfFoundation = 0;             // Год основания
	private int numberOfPerformance = 0;

	public Theatre() {                            // Конструктор Театра
		this.nameTh = toWriteName();
		this.yearOfFoundation = toWriteYear();
		this.numberOfStages = toWriteNumberOfStages();
		this.stages = toWriteStages();
		System.out.println();
	}

	public Theatre(String name, int year, int count, Stage stages[]) {   // Конструктор с параметром
		this.nameTh = name;
		this.yearOfFoundation = year;
		this.numberOfStages = count;
		this.stages = stages;
	}

	public String getNameTh() {                               // Возвращение названия Театра
		return nameTh;
	}

	public int getYearOfFoundation() {                        // Возвращения года основания Театра
		return yearOfFoundation;
	}

	public int getNumberOfStages() {                          // Возвращения года основания Театра
		return numberOfStages;
	}

	public Stage getStage(int num) {
		return stages[num];
	}

	public void toPrint() {                                   // Вывод информации о Театре
		if (!getNameTh().isEmpty() && getYearOfFoundation() != 0) {
			System.out.print("Название: ");
			System.out.println(getNameTh());
			System.out.print("Год основания: ");
			System.out.println(getYearOfFoundation());
			System.out.print("Количество сцен: ");
			System.out.println(getNumberOfStages());
			System.out.println();
			int count = 0;
		    for (int i = 0; i < getNumberOfStages(); i++) {
				System.out.println("\tСцена №" + (i + 1) + ':');
				getStage(i).toPrint();
				count += getStage(i).getNumberOfPerformances();
			}
			System.out.println();
		}

	}

	public void addStage() {                                  // Добавление сцены в Театр
		if(getNumberOfStages() < 5) { 
			stages[getNumberOfStages()] = new Stage();
			increasingNumberOfStages();
		}
		else 
			System.out.println("Максимально допустимое значение кол-ва сцен: 5!");
		System.out.println();
	}

	public void addStage(int count, Stage stage[]) {          // Добавление сцены в Театр
		if(getNumberOfStages() < 5) {
			for(int i = 0; i < count; i++) {
				stages[getNumberOfStages()] = stage[i];
				increasingNumberOfStages();
			}
		}
		else 
			System.out.println("Максимально допустимое значение кол-ва сцен: 5!");
	}

	public void delStage(int numStage) {
		if (numStage >= 0 && numStage < getNumberOfStages()) {
		for (int i = numStage; i < getNumberOfStages() - 1; i++) {
			stages[i] = stages[i + 1];
		}
		decreaseNumberOfStages();
	}
	else
		System.out.println("Номер сцены должен быть в промежутке от 0 до" + (numberOfStages - 1) + " (включая).");
	}

	private String toWriteName() {                 // Ввод названия Театра
		System.out.print("Название театра: ");
		Scanner console = new Scanner(System.in);
		String name = console.nextLine();
		while (name.isEmpty()) {                   // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			name = console.nextLine();
		}
		return name;
	}

	private int toWriteYear() {                    // Ввод года основания Театра
		System.out.print("Год основания: ");
		Scanner console = new Scanner(System.in);
		int year = console.nextInt();
		console.nextLine();
		while (year < 1740 || year > 2021) {       // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			year = console.nextInt();
			console.nextLine();
		}
		return year;
	}

	private int toWriteNumberOfStages() {          // Ввод количества Сцен
		int number;
		System.out.print("Количество сцен: ");
		Scanner console = new Scanner(System.in);
		number = console.nextInt();
		console.nextLine();
		while (number < 0 || number > 5) {         // Защита от неверного ввода
			System.out.println("Неверный формат ввода!");
			number = console.nextInt();
			console.nextLine();
		}
		return number;
	}

	private Stage[] toWriteStages() {               // Ввод информации о сценах Театра   
		Stage stages[] = new Stage[getNumberOfStages()];
		for (int i = 0; i < getNumberOfStages(); i++) {
			stages[i] = new Stage();
		}
		return stages;
	}

	private void increasingNumberOfStages() {   // Увеличение кол-ва сцен
		numberOfStages++;
	}

	private void decreaseNumberOfStages() {     // Уменьшение числа сцен
		numberOfStages--;
	}
}