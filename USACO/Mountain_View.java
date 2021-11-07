import java.io.*;
import java.util.*;

public class Mountain_View {

    static class Base implements Comparable<Base> {
        public int xL, xR;

        public Base(int left, int right) {
            xL = left;
            xR = right;
        }

        public int compareTo(Base b) {
            if (xL == b.xL) {
                return b.xR - xR;
            }
            return xL - b.xL;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("mountains.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mountains.out")));

        int N = Integer.parseInt(in.readLine());

        ArrayList<Base> mountains = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            mountains.add(new Base(x - y, x + y));
        }
        Collections.sort(mountains);

        int count = 1;
        int last_xR = mountains.get(0).xR;
        for (int i = 1; i < N; i++) {
            if (mountains.get(i).xR > last_xR) {
                last_xR = mountains.get(i).xR;
                count++;
            }
        }

        out.println(count);

        in.close();
        out.close();
    }
}