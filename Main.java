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
		System.out.println("Актеров в 1м театре: " + (theatre_1.getNumberOfActors()) + ", актеров во 2м театре: " + theatre_2.getNumberOfActors());
		System.out.println("\nЗначение общего количества актеров до обращения к методу: " + Theatre.getAllAct());
		Theatre.countAllAct(theatre_1);
		Theatre.countAllAct(theatre_2);
		System.out.println("\nЗначение общего количества актеров после обращения к методу: " + Theatre.getAllAct());
		System.out.println("\nРаботников в 1м театре: " + theatre_1.getNumberOfStageDirectors() + ", работников во 2м театре: " + theatre_2.getNumberOfStageDirectors());
		System.out.println("\nЗначение общего количества работников до обращения к методу: " + Theatre.getAllDir());
		Theatre.countAllDir(theatre_1);
		Theatre.countAllDir(theatre_2);
		System.out.println("\nЗначение общего количества актеров после обращения к методу: " + Theatre.getAllDir());
	}
}