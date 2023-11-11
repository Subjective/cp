import java.util.Scanner;

public class TrickyTravels {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] board = new int[N];
        for (int i = 0; i < N; i++) {
            board[i] = in.nextInt();
        }
        int currentTile = 0;
        boolean possible = false;
        for (int moves = 0; moves < N; moves++) {
            if (board[currentTile] == 0) {
                System.out.println(moves);
                possible = true;
                break;
            }
            currentTile = (currentTile + board[currentTile]) % N;
        }
        if (!possible) System.out.println(-1);
    }
}
