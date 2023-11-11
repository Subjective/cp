import java.io.*;

public class CircularBarn {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("cbarn.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cbarn.out")));

        int N = Integer.parseInt(in.readLine());
        int[] capacity = new int[N];

        for (int i = 0; i < N; i++) {
            capacity[i] = Integer.parseInt(in.readLine());
        }

        int minDistance = N * N * 100;

        for (int door = 0; door < N; door++) {
            int currentDistance = 0;
            for (int offset = 0; offset < N; offset++) {
                currentDistance += offset * capacity[(door + offset) % N];
            }
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
            }
        }

        out.println(minDistance);

        in.close();
        out.close();
    }
}
