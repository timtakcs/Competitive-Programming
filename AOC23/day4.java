package AOC23;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Map;

public class day4 {
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

            // for (String line: input) {
            //     ans += part1(line);
            // }

            if (writer != null) {
                writer.println(ans);
                writer.close();
            }
        }
    }

    private static long part1(String s) {
        HashSet<String> set = new HashSet<>();
        HashSet<String> used = new HashSet<>();

        String[] parts = s.split(":");

        String cards = parts[1];

        String[] game = cards.split("\\|");

        game[0] = game[0].trim();
        game[1] = game[1].trim();

        String[] winning_nums = game[0].split("\\s+");
        String[] my_nums = game[1].split("\\s+");

        for (int i = 0; i < winning_nums.length; i++) {
            set.add(winning_nums[i]);
        }

        long score = 0;

        for (int i = 0; i < my_nums.length; i++) {
            if (set.contains(my_nums[i]) && !used.contains(my_nums[i])) {
                used.add(my_nums[i]);
                if (score == 0) {
                    score++;
                } else {
                    score *= 2;
                }
            }
        }

        return score;
    }

    private static long part2(ArrayList<String> input) {
        ArrayList<Integer> totals = new ArrayList<>();
        ArrayList<Integer> wins = new ArrayList<>();

        for (int i = 0; i < input.size(); i++) {
            totals.add(1);
            wins.add(0);
        }

        for (int i = 0; i < input.size(); i++) {
            HashSet<String> set = new HashSet<>();
            HashSet<String> used = new HashSet<>();

            String[] cards = input.get(i).split(":");
            String[] game = cards[1].split("\\|");

            String[] winning_nums = game[0].split("\\s+");
            String[] my_nums = game[1].split("\\s+");

            for (int j = 0; j < winning_nums.length; j++) {
                set.add(winning_nums[j]);
            }

            int score = 0;

            for (int j = 0; j < my_nums.length; j++) {
                if (set.contains(my_nums[j]) && !used.contains(my_nums[j])) {
                    used.add(my_nums[j]);
                    score++;
                }
            }

            wins.set(i, score);
        }

        for (int i = 0; i < input.size(); i++) {
            for (int j = i + 1; j < i + wins.get(i); j++) {
                totals.set(j, totals.get(j) + totals.get(i));
            }
        }

        long ans = 0;
        for (int i = 0; i < input.size(); i++) {
            ans += totals.get(i);
        }

        return ans;
    }
}
