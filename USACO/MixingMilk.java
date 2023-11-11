import java.io.*;
import java.util.StringTokenizer;

public class MixingMilk {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("mixmilk.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mixmilk.out")));

        int[] C = new int[3];
        int[] M = new int[3];

        for (int i = 0; i < 3; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            C[i] = Integer.parseInt(st.nextToken());
            M[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < 100; i++) {
            int b1 = i % 3, b2 = (i + 1) % 3;
            int amt = Math.min(M[b1], C[b2] - M[b2]);

            M[b1] -= amt;
            M[b2] += amt;
        }

        for (int i = 0; i < 3; i++) {
            out.println(M[i]);
        }

        in.close();
        out.close();
    }

}
