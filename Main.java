import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Stage[] stages_1 = new Stage[2];
		Performance[] performance = new Performance[2];
		performance[0] = new Performance("Ромео и Джульетта", 200, 1999);
		performance[1] = new Performance("Призрак оперы", 250, 1990);
		stages_1[0] = new Stage("Большая", 600, 2, performance);
		Theatre [][] theatre = new Theatre [2][1];
		theatre[0][0] = new Theatre("Драматический", 1990, 1, stages_1);
		theatre[1][0] = new Theatre("Музыкальный", 2000, 1, stages_1);
		Actor[] actors = new Actor[2];
		actors[0] = new Actor("Михаил",  "Боярский", 65, theatre[0][0]);
		actors[1] = new Actor("Михаил",  "Коровин", 35, theatre[1][0]);
		System.out.println("Задание №1\n");
		System.out.println("Одномерный массив:");
		for(int i = 0; i < 2; i++)
			performance[i].toPrint();
		System.out.println("Двумерный массив:");
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 1; j++)
				theatre[i][j].toPrint();
	}
}