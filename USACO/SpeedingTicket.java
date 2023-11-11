import java.io.*;
import java.util.StringTokenizer;

public class SpeedingTicket {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("speeding.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));
        
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

        int[] road = new int[100];
        int currentMile = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            for (int j = currentMile; j < currentMile + l; j++) {
                    road[j] = s;
            }

            currentMile += l;
        }

        int[] drive = new int[100];
        currentMile = 0;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());

            for (int j = currentMile; j < currentMile + l; j++) {
                drive[j] = s;
            }

            currentMile += l;
        }

        int maxOver = 0;

        for (int i = 0; i < 100; i++)
            maxOver = Math.max(maxOver, drive[i] - road[i]);

        out.println(maxOver);

        in.close();
        out.close();
    }
}
