package AOC23;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Map;
import java.util.HashMap;
import java.util.List;

public class day5 {
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
            long ans = part1(input);

            if (writer != null) {
                writer.println(ans);
                writer.close();
            }
        }
    }

    private static class Entry {
        public long s_start;
        public long t_start;
        public long len;

        Entry(long s, long t, long len) {
            this.s_start = s;
            this.t_start = t;
            this.len = len;
        }
    }

    private static long part1(ArrayList<String> input) {
        Map<String, ArrayList<Entry>> ranges = new HashMap<>();
        ArrayList<String> keys = new ArrayList<>();
        ArrayList<Long> seeds = new ArrayList<>();

        String[] seeds_chars = input.get(0).split(":")[1].trim().split(" ");
        for (int i = 0; i < seeds_chars.length; i++) {
            seeds.add(Long.parseLong(seeds_chars[i]));
        }

        keys.add("seed-to-soil");
        keys.add("soil-to-fertilizer");
        keys.add("fertilizer-to-water");
        keys.add("water-to-light");
        keys.add("light-to-temperature");
        keys.add("temperature-to-humidity");
        keys.add("humidity-to-location");

        ranges.put("seed-to-soil", new ArrayList<>());
        ranges.put("soil-to-fertilizer", new ArrayList<>());
        ranges.put("fertilizer-to-water", new ArrayList<>());
        ranges.put("water-to-light", new ArrayList<>());
        ranges.put("light-to-temperature", new ArrayList<>());
        ranges.put("temperature-to-humidity", new ArrayList<>());
        ranges.put("humidity-to-location", new ArrayList<>());

        String cur_key = "";

        for (int i = 1; i < input.size(); i++) {
            String row = input.get(i);
            
            if (row.length() == 0) continue;
            
            if (Character.isDigit(row.charAt(0))) {
                String[] nums = row.split(" ");
                ranges.get(cur_key).add(new Entry(Long.parseLong(nums[1]), Long.parseLong(nums[0]), Long.parseLong(nums[2])));
            } else if (Character.isLetter(row.charAt(0))) {
                cur_key = row.split(" ")[0];
                System.out.println(cur_key);
            }
        }

        ArrayList<Long> ans = new ArrayList<>();

        for (int i = 0; i < seeds.size(); i++) {

            long x = seeds.get(i);

            for (String key: keys) {
                ArrayList<Entry> cans = ranges.get(key);

                for (Entry e: cans) {
                    if (x >= e.s_start && x < e.s_start + e.len) {
                        x = e.t_start + (x - e.s_start);
                        break;
                    }
                }
            }

            ans.add(x);
        }

        long min = ans.get(0);

        for (int i = 1; i < ans.size(); i++) {
            if (ans.get(i) < min) {
                min = ans.get(i);
            }
        }

        return min;
    }
}
