import java.io.*;
import java.util.StringTokenizer;

public class NumberSpiral {
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
        int T = r.nextInt();
        for (int i = 0; i < T; i++) {
            long y = r.nextInt();
            long x = r.nextInt();

            if (y > x) {
                if (y % 2 == 0) {
                    pw.println(y*y - x + 1);
                }
                else {
                    pw.println((y - 1)*(y - 1) + x);
                }
            }
            else if (y < x) {
                if (x % 2 == 0) {
                    pw.println((x - 1)*(x - 1) + y);
                }
                else {
                    pw.println(x*x - y + 1);
                }
            }
            else {
                pw.println(x*x - x + 1);
            }
        }
        r.reader.close();
        pw.close();
    }
}
