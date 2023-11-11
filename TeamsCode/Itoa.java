import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Itoa {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/itoa.txt"));
        int N = in.nextInt();
        char[] digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        for (int i = 0; i < N; i++) {
            int baseTo = in.nextInt();
            int baseFrom = in.nextInt();
            String num = in.next();
            int numBaseTen = 0;

            for (int j = 0; j < num.length(); j++) {
                int digit = Character.getNumericValue(num.charAt(j));
                numBaseTen += digit * Math.pow(baseFrom, num.length() - 1 - j);
            }

            StringBuilder convertedNum = new StringBuilder();
            while (numBaseTen > 0) {
                char digit = digits[numBaseTen % baseTo];
                convertedNum.insert(0, digit);
                numBaseTen /= baseTo;
            }

            System.out.println(convertedNum);
        }
    }
    // alternative solution
    public static String convertFromBaseToBase(String str, int fromBase, int toBase) {
        return Integer.toString(Integer.parseInt(str, fromBase), toBase);
    }
}
