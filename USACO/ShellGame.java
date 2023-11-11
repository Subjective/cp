import java.io.*;
import java.util.StringTokenizer;

public class ShellGame {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("shell.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shell.out")));

        int N = Integer.parseInt(in.readLine());
        int[][] swaps = new int[N][3];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            swaps[i] = new int[] { Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) };
        }

        int maxGuesses = 0;

        for (int i = 0; i < 3; i++) {
            int[] shells = new int[3];
            shells[i] = 1;
            int guesses = 0;

            for (int j = 0; j < swaps.length; j++) {
                int a = swaps[j][0] - 1;
                int b = swaps[j][1] - 1;

                swap(shells, a, b);

                if (shells[swaps[j][2] - 1] == 1)
                    guesses++;
            }

            if (guesses > maxGuesses)
                maxGuesses = guesses;
        }
        
        out.println(maxGuesses);

        in.close();
        out.close();
    }

    private static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

}
