import java.util.Scanner;

public class SleepySpider {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] walls = new int[6];
        for (int i = 0; i < 6; i++) {
            walls[i] = in.nextInt();
        }

        for (int day = 0; day < N; day++) {
            int[] moves = new int[6];
            for (int j = 0; j < 6; j++) {
                if (walls[(j + 1) % 6] < walls[j]) {
                    int numMoves = walls[j] / 2;
                    moves[j] -= numMoves;
                    moves[(j + 1) % 6] += numMoves;
                }
            }
            for (int j = 0; j < 6; j++) {
                walls[j] += moves[j];
            }
        }

        for (int i = 0; i < 6; i++) {
            System.out.println(walls[i]);
        }
    }
}
