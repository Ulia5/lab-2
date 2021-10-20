import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[5];
		Stage[] stages_2 = new Stage[5];
		stages_1[0] = new Stage("Большая", 600);
		Theatre theatre_1 = new Theatre("Драматический", 1990, 1, stages_1);
		Theatre theatre_2 = new Theatre();
		for(int i = 0; i < 1; i++) {
			stages_2[i] = new Stage();
		}
		theatre_1.addStage();
		theatre_1.addStage(1, stages_2);
		theatre_1.toPrint();
		theatre_1.delStage(2);
		theatre_1.toPrint();
		theatre_2.toPrint();
	}
}