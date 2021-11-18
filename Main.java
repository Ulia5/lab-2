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
		StageDirector sd_1 = new StageDirector(theatre_1);
		StageDirector sd_2 = new StageDirector("Иван", "Иванов", 28, theatre_1);
		sd_1.toPrint();
		sd_2.toPrint();
		sd_1.addPerformanceDir(performance[1]);
		sd_1.toPrint();
		performance[1].toPrint();
		sd_1.delPerformanceDir(performance[1]);
		sd_1.toPrint();
		performance[1].toPrint();
	}
}