import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
		performance[1] = new Performance("Любовь и голуби", 180, 1990);
		stages_1[0] = new Stage("Большая", 600, 2, performance);
		Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
		theatre_1.toPrint();
		Actor actor_1 = new Actor(theatre_1);
		Actor actor_2 = new Actor("Иван", "Иванов", 28, theatre_1);
		actor_1.toPrint();
		actor_2.toPrint();
		actor_1.addPerformanceAct(performance[1]);
		actor_1.toPrint();
		performance[1].toPrint();
		actor_1.delPerformanceAct(performance[1]);
		actor_1.toPrint();
		performance[1].toPrint();
	}
}