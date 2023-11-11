import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class UnitConversion {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/unitConversion.txt"));
        int N = in.nextInt();

        for (int i = 0; i < N; i++) {
            String unit = in.next();
            int measure = unit.equals("i") ? (int) (in.nextInt() * 2.54) : in.nextInt();
            int cm = measure % 100;
            measure /= 100;
            int m = measure % 1000;
            measure /= 1000;
            int km = measure;
            System.out.printf("%d %d %d\n", km, m, cm);
        }
    }
}
