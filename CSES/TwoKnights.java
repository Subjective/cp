import java.io.*;
import java.util.StringTokenizer;

public class TwoKnights {
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

        for (int k = 1; k <= N; k++) {
            if (k == 1) pw.println(0);
            else {
                long k1 = k * k;
                long k2 = (k1 * (k1 - 1)) / 2;
                long k3 = 4 * (k - 1) * (k - 2);
                pw.println(k2 - k3 + " ");
            }
        }

        r.reader.close();
        pw.close();
    }
}
