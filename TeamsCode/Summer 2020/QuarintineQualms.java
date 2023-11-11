import java.util.Scanner;

public class QuarintineQualms {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t1 = in.nextInt();
        int t2 = in.nextInt();
        int N = in.nextInt();
        int intersection = 0;

        int[][] people = new int[N][2];
        for (int i = 0; i < N; i++) {
            people[i][0] = in.nextInt();
            people[i][1] = in.nextInt();
        }

        for (int[] person : people) {
            if (! (t2 < person[0] || person[1] < t1)) {
                intersection += Math.abs((Math.max(t1, person[0]) - Math.min(t2, person[1])));
            }
        }
        System.out.println(intersection * 2);
    }
}
