public class Problem_3_COW_Operations {
     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String r = "COW";
        String str = in.next();
        int[][] sums = new int[str.length() + 1][3];
        for (int i = 1; i < str.length() + 1; i++) {
            for (int j = 0; j < 3; j++) {
                sums[i][j] = sums[i - 1][j];
            }
            sums[i][r.indexOf(str.charAt(i - 1))]++;
        }
        int tests = in.nextInt();
        for (int i = 0; i < tests; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            int[] subsums = {sums[end][0] - sums[start - 1][0], sums[end][1] - sums[start - 1][1], sums[end][2] - sums[start - 1][2]};
            boolean correct;
            if (subsums[0] % 2 == 1) {
                if (subsums[1] % 2 == 0 && subsums[2] % 2 == 0) {
                    correct = true;
                } else {
                    correct = false;
                }
            } else {
                if (subsums[1] % 2 == 1 && subsums[2] % 2 == 1) {
                    correct = true;
                } else {
                    correct = false;
                }
            }
            if (correct) {
                System.out.print("Y");
            } else {
                System.out.print("N");
            }
        }
    }
}
