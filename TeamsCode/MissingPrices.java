import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class MissingPrices {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/missingPrices.txt"));
        int N = in.nextInt();

        for (int i = 0; i < N; i++) {
            double X = 0;
            String base = in.next();
            String tax = in.next();
            String result = in.next();
            if (base.equals("X")) {
                X = Double.parseDouble(result) * (100 / (100 + Double.parseDouble(tax)));
            }
            else if (tax.equals("X")) {
                X = (100 * Double.parseDouble(result)) / Double.parseDouble(base) - 100;
            }
            else {
                X = (100 + Double.parseDouble(tax)) / 100 * Double.parseDouble(base);
            }
            System.out.printf("%5.2f%n", X);
        }
    }
}
