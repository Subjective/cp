import java.util.Scanner;

public class PerfectPromposal {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int M = in.nextInt();
        int numSuccesfulDays = 0;
        for (int i = 7; i > 0; i--) {
            int Q = in.nextInt();
            if (Q * i >= M) {
                numSuccesfulDays++;
            }
        }
        System.out.println(numSuccesfulDays);
    }
}
