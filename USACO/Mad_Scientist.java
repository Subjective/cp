import java.io.*;

public class Mad_Scientist {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("breedflip.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("breedflip.out")));

        int N = Integer.parseInt(in.readLine());
        String A = in.readLine(); String B = in.readLine();

        int ans = 0;
        boolean mismatched = false;
        for (int i = 0; i < N; i++) {
            if (A.charAt(i) == B.charAt(i)) {
                if (mismatched) {
                    ans++;
                    mismatched = false;
                }
            } else {
                mismatched = true;
            }
        }
        out.println(ans);

        in.close();
        out.close();
    }

}