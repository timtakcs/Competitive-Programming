package AOC23;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class day6 {
    public static void main(String[] args) {
        String inputFilePath = "input.txt";
        String outputFilePath = "output.txt";

        PrintWriter writer = null;

        ArrayList<String> input = new ArrayList<>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
            writer = new PrintWriter(outputFilePath);
            
            String line;
            while ((line = reader.readLine()) != null) {
                input.add(line);
            }

            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            long ans = part2(input);

            if (writer != null) {
                writer.println(ans);
                writer.close();
            }
        }
    }

    private static long part1(ArrayList<String> input) {
        String[] pre_times = input.get(0).split(":")[1].trim().split("\\s+");
        String[] pre_distances = input.get(1).split(":")[1].trim().split("\\s+");

        int n = pre_times.length;

        ArrayList<Long> times = new ArrayList<>();
        ArrayList<Long> distances = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            times.add(Long.parseLong(pre_times[i]));
            distances.add(Long.parseLong(pre_distances[i]));
        }

        ArrayList<Long> ways = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            long w = 0;
            for (long hold = 0; hold < times.get(i); hold++) {
                long cur_dist = (times.get(i) - hold) * hold;
                if (cur_dist > distances.get(i)) {
                    w++;
                }
            }
            ways.add(w);
        }

        long ans = 1;

        for (Long w: ways) {
            ans *= w;
        }

        return ans;
    }

    private static long part2(ArrayList<String> input) {
        String[] pre_times = input.get(0).split(":")[1].trim().split("\\s+");
        String[] pre_distances = input.get(1).split(":")[1].trim().split("\\s+");

        int n = pre_times.length;

        StringBuilder time = new StringBuilder();
        StringBuilder distance = new StringBuilder();

        for (int i = 0; i < n; i++) {
            time.append(pre_times[i]);
            distance.append(pre_distances[i]);
        }

        long t = Long.parseLong(time.toString());
        long d = Long.parseLong(distance.toString());

        // System.out.println(t);
        // System.out.println(d);

        long w = 0;
        for (long hold = 0; hold < t; hold++) {
            long cur_dist = (t - hold) * hold;
            if (cur_dist > d) {
                w++;
            }
        }

        return w;
    }
}
