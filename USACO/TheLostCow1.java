import java.io.*;
import java.util.StringTokenizer;

public class TheLostCow1 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("lostcow.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lostcow.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
        int totalDistance = 0;
        int dir = 1;
        int dist = 1;
        while (true) {
            if (dir == 1 && x <= y && y <= x + dist || dir == -1 && x >= y && y >= x - dist) {
                totalDistance += Math.abs(y - x);
                out.println(totalDistance);
                break;
            } else {
                totalDistance += dist * 2;
                dist *= 2;
                dir *= -1;
            }
        }

        in.close();
        out.close();
    }
}

