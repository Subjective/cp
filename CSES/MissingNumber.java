import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class MissingNumber {
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
        TreeSet<Integer> set = new TreeSet<>();

        for (int i = 1; i <= N; i++) {
            set.add(i);
        }
        for (int i = 0; i < N - 1; i++) {
            set.remove(r.nextInt());
        }
        pw.println(set.first());

        r.reader.close();
        pw.close();
    }
}
