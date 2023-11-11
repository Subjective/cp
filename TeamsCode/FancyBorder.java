import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class FancyBorder {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/fancyBorder.txt"));
        int N = in.nextInt();

        System.out.println("\\--*****--/");
        for (int i = 0; i < N; i++) {
            StringBuilder sb = new StringBuilder("|         |");
            String word = in.next();
            sb.replace(1, word.length() + 1, word);
            System.out.println(sb);
        }
        System.out.println("/--*****--\\");
    }
}
