import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class FizzBuzzBloop {

    static class Rule {
        int multiple;
        String word;

        public Rule (int multiple, String word)  {
            this.multiple = multiple;
            this.word = word;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/fizzBuzzBloop.txt"));
        int start = in.nextInt();
        int end = in.nextInt();
        int N = in.nextInt();
        Rule[] rules = new Rule[N];

        for (int i = 0; i < N; i++) {
            rules[i] = new Rule(in.nextInt(), in.next());
        }

        for (int i = start; i <= end; i++) {
            StringBuilder word = new StringBuilder();
            for (Rule r : rules) {
                if (i % r.multiple == 0) {
                    word.append(r.word);
                }
            }
            System.out.println(word.length() == 0 ? i : word);
        }

    }
}


