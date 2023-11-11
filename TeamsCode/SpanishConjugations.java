import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class SpanishConjugations {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/spanishConjugations.txt"));
        int N = in.nextInt();
        String[][] conjugations = new String[][] { { "o", "o", "o" }, { "as", "es", "es" },
            { "a", "e", "e" }, { "amos", "emos", "imos" }, { "an", "en", "en" } };

        for (int i = 0; i < N; i++) {
            String verb = in.next();
            String beginning = verb.substring(0, verb.length() - 2);
            String ending = verb.substring(verb.length() - 2);
            for (int j = 0; j < 5; j++) {
                if (ending.equals("ar"))
                    System.out.println(beginning + conjugations[j][0]);
                else if (ending.equals("er"))
                    System.out.println(beginning + conjugations[j][1]);
                else
                    System.out.println(beginning + conjugations[j][2]);
            }
        }
    }
}
