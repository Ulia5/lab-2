import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
		performance[1] = new Performance("Любовь и голуби", 180, 1990);
		stages_1[0] = new Stage("Большая", 600, 2, performance);
		Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
		Theatre theatre_2 = new Theatre("Музыкальный", 2000, 1, stages_1);
		Actor[] actors = new Actor[2];
		actors[0] = new Actor("Михаил",  "Боярский", 65, theatre_1);
		actors[0] = new Actor("Михаил",  "Коровин", 35, theatre_2);
		System.out.println("Задание №1\n");
		System.out.println("Конструктор со всеми параметрами:");
		actors[0].toPrint();
		System.out.println("Конструктор с 1 параметром:");
		Actor actor = new Actor(theatre_1);
		System.out.println("Конструктор без параметром:");
		Actor actor1 = new Actor();
		System.out.println("Инициализация массива конструктором с одним параметром:");
		Actor[] actors1 = new Actor [2];
		for(int i = 0; i < 2; i++)
			actors1[i] = new Actor(theatre_2);
	}
}