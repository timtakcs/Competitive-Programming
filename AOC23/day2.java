package AOC23;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;
import java.util.HashMap;

class day2 {
    public static void main(String[] args) {
        String inputFilePath = "input.txt";
        String outputFilePath = "output.txt";

        int ans = 0;
        PrintWriter writer = null;

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
            writer = new PrintWriter(outputFilePath);
            
            String line;
            while ((line = reader.readLine()) != null) {
                ans += part2(line);
            }

            reader.close(); // Close the reader
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (writer != null) {
                writer.println(ans);
                writer.close(); // Close the writer
            }
        }
    }

    private static int part1(String s) {
        String[] main_parts = s.split(":");

        Map<String, Integer> m = new HashMap<>();

        m.put("red", 12);
        m.put("blue", 14);
        m.put("green", 13);

        String[] rounds = main_parts[1].split(";");
        for (String round : rounds) {
            String[] balls = round.split(",");
            for (String draw : balls) {
                String[] cnt = draw.split(" ");

                if (m.get(cnt[2]) < Integer.parseInt(cnt[1])) return 0;
            }
        }

        return Integer.parseInt(main_parts[0].split(" ")[1]);
    }

    private static int part2(String s) {
        String[] main_parts = s.split(":");

        Map<String, Integer> m = new HashMap<>();

        m.put("red", 0);
        m.put("blue", 0);
        m.put("green", 0);

        String[] rounds = main_parts[1].split(";");
        for (String round : rounds) {
            String[] balls = round.split(",");
            for (String draw : balls) {
                String[] cnt = draw.split(" ");

                m.put(cnt[2], Math.max(m.get(cnt[2]), Integer.parseInt(cnt[1])));
            }
        }

        return m.get("red") * m.get("green") * m.get("blue");
    }
}