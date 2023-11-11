import java.io.*;
import java.util.StringTokenizer;

public class Permutations {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }
        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { // reads in the next int
            return Integer.parseInt(next());
        }
        public long nextLong() { // reads in the next long
            return Long.parseLong(next());
        }
        public double nextDouble() { // reads in the next double
            return Double.parseDouble(next());
        }
    }

    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        int N = r.nextInt();

        if (N == 1) {
            pw.print("1");

            r.reader.close();
            pw.close();
            System.exit(0);
        }

        else if (N == 2 || N == 3) {
            pw.print("NO SOLUTION");

            r.reader.close();
            pw.close();
            System.exit(0);
        }

        for (int i = 2; i <= N; i+=2) {
            pw.print(i + " ");
        }

        for (int i = 1; i <= N; i+=2) {
            pw.print(i + " ");
        }

        r.reader.close();
        pw.close();
    }
}