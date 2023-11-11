import java.io.*;
import java.util.StringTokenizer;

public class TheBovineShuffle {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("shuffle.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));
        
        int N = Integer.parseInt(in.readLine());

        int[] shuffle = new int[N];
        int[] cows = new int[N];

        StringTokenizer st = new StringTokenizer(in.readLine());

        for (int i = 0; i < shuffle.length; i++) {
            shuffle[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(in.readLine());

        for (int i = 0; i < cows.length; i++) {
            cows[i] = Integer.parseInt(st.nextToken());
        }

        cows = shuffle(shuffle, cows);

        for (int i = 0; i < cows.length; i++) {
            out.println(cows[i]);
        }

        in.close();
        out.close();
    }

    private static int[] shuffle(int[] shuffle, int[] cows) {
        for (int i = 0; i < 3; i++) {
            int[] tmp = new int[cows.length];
            for (int j = 0; j < shuffle.length; j++) {
                tmp[j] = cows[shuffle[j] - 1];
            }
            cows = tmp;
        }
        return cows;
    }
}
