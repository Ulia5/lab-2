import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
		performance[1] = new Performance("Любовь и голуби", 180, 1990);
		stages_1[0] = new Stage("Большая", 600, 2, performance);
		Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
		System.out.println("Задание №1\n");
		theatre_1.toPrint();
		System.out.println("\nЗадание №2\n");
		Theatre theatre_2 = new Theatre();
	}
}