import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class SimplerNoteSorting {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("data/noteSorting.txt"));
        int N = in.nextInt();
        double[] notes = new double[N];

        HashMap<String, Integer> noteScale = new HashMap<>();
        noteScale.put("C", -9);
        noteScale.put("C#", -8);
        noteScale.put("D", -7);
        noteScale.put("D#", -6);
        noteScale.put("E#", -5);
        noteScale.put("F", -4);
        noteScale.put("F#", -3);
        noteScale.put("G", -2);
        noteScale.put("G#", -1);
        noteScale.put("A", 0);
        noteScale.put("A#", 1);
        noteScale.put("B", 2);

        for (int i = 0; i < N; i++) {
            int octave = in.nextInt();
            String note = in.next();
            double exp = noteScale.get(note) + 12 * (octave - 4);
            double noteValue = 440 * Math.pow(1.05946, exp);
            notes[i] = noteValue;
        }
        Arrays.sort(notes);
        for (int i = 0; i < notes.length; i++) {
            System.out.printf("%1.0f\n", notes[i]);
        }
    }
}
