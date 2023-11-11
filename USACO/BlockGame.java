import java.io.*;
import java.util.StringTokenizer;

public class BlockGame {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("blocks.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
        
        int N = Integer.parseInt(in.readLine());
        String[][] boards = new String[N][2];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            boards[i][0] = st.nextToken();
            boards[i][1] = st.nextToken();
        }

        int[] ans = new int[26];

        for (int i = 0; i < N; i++) {
           int min1[] = new int[26];
           int min2[] = new int[26];
           
            String w1 = boards[i][0], w2 = boards[i][1];

            for (int j = 0; j <  w1.length(); j++)
                min1[w1.charAt(j) - 'a']++;

            for (int j = 0; j < w2.length(); j++)
               min2[w2.charAt(j) - 'a']++;

            for (int j = 0; j < 26; j++)
                ans[j] += Math.max(min1[j], min2[j]);
        }

        for (int i = 0; i < ans.length; i++)
            out.println(ans[i]);

        in.close();
        out.close();
    }
}
