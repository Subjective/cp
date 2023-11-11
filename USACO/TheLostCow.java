import java.io.*;
import java.util.StringTokenizer;

public class TheLostCow {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("lostcow.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lostcow.out")));
        
        StringTokenizer st = new StringTokenizer(in.readLine());

        int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());

        int totalDistance = 0;

        for (int i = 0; i < 9; i++) {
            int distance = pow(i);
            int position = x + distance;
            totalDistance += Math.abs(distance);
            if (passes(x, position, y)) {
                totalDistance -= Math.abs(position - y);
                break;
            }
            totalDistance += Math.abs(distance);
        }

        out.println(totalDistance);
                
        in.close();
        out.close();
    }

    private static int pow(int p) {
        int num = 1;
        for (int i = 0; i < p; i++) {
            num *= -2;
        }
        return num;
    }

    private static boolean passes(int start, int end, int target) {
        if (start <= target && end > target)
            return true;
        else if (start >= target && end < target)
            return true;
        return false;
    }
}
