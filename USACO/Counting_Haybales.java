import java.io.*;
import java.util.*;

public class Counting_Haybales {

    public static int search(int[] pos, int val) {
        int l = 0, h = pos.length - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (pos[m] < val) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return l;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("haybales.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        int[] pos = new int[N];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++) {
            pos[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(pos);

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(in.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            out.println(search(pos, B + 1) - search(pos, A));
        }

        in.close();
        out.close();
    }
}