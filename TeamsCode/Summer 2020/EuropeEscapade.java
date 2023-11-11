import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class EuropeEscapade {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        String[][] people = new String[N + 1][];
        for (int i = 0; i < N + 1; i++) {
            people[i] = new String[in.nextInt()];
        }
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < people[i].length; j++) {
                people[i][j] = in.next();
            }
        }
        int maxNumTrips = 0;
        for (String[] person : people) {
            if (person.length > maxNumTrips) {
                maxNumTrips = person.length;
            }
        }
        for (int i = 0; i < people.length; i++) {
            System.out.println(Arrays.toString(people[i]));
        }

        String[][] tmp = new String[N + 1][maxNumTrips];
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < people[i].length; j++) {
                tmp[i][j] = people[i][j];
            }
        }
        System.out.println("\n");
        people = tmp;
        for (int i = 0; i < people.length; i++) {
            System.out.println(Arrays.toString(people[i]));
        }


    }
}
