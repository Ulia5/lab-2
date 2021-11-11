import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[5];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
		stages_1[0] = new Stage("Большая", 600, 1, performance);
		Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
		theatre_1.toPrint();
		theatre_1.getStage(0).delPerformance(0);
		theatre_1.toPrint();
		theatre_1.getStage(0).addPerformance();
		Performance[] newPerf = new Performance[1];
		newPerf[0] = new Performance("Гроза", 180, 1999);
		theatre_1.getStage(0).addPerformance(1, newPerf);
		theatre_1.toPrint();
	}
}