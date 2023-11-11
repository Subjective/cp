import java.util.Scanner;

public class ScaredSkiing {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double x1 = in.nextDouble();
        double y1 = in.nextDouble();
        double x2 = in.nextDouble();
        double y2 = in.nextDouble();
        double slope = ((y1 - y2) / (x1 - x2));
        System.out.println((int) slope);
    }
}
