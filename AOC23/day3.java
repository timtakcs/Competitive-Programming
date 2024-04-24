package AOC23;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Map;
import java.util.Objects;
import java.util.HashMap;

public class day3 {
     public static void main(String[] args) {
        String inputFilePath = "input.txt";
        String outputFilePath = "output.txt";

        PrintWriter writer = null;

        ArrayList<String> mat = new ArrayList<>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFilePath));
            writer = new PrintWriter(outputFilePath);
            
            String line;
            while ((line = reader.readLine()) != null) {
                mat.add(line);
            }

            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            long ans = part2(mat);

            if (writer != null) {
                writer.println(ans);
                writer.close();
            }
        }
    }

    public static class Pair {
        private final int x;
        private final int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return x == pair.x && y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public String toString() {
            return this.x + " " + this.y;
        }
    }

    private static boolean check(ArrayList<String> mat, String row, int x, int y) {
        while (x < row.length() && row.charAt(x) >= '0' && row.charAt(x) <= '9') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nx = x + i - 1;
                    int ny = y + j - 1;

                    if (nx < row.length() && nx >= 0 && ny < mat.size() && ny >= 0) {
                        char c = mat.get(ny).charAt(nx);
                        if (c != '.' && (c > '9' || c < '0')) return true;
                    }
                }
            }
            
            x++;
        }

        return false;
    }

    private static int part1(ArrayList<String> mat) {
        int ans = 0;
        int r = 0;
        for (String row : mat) {
            int n = row.length();
            int i = 0;

            while (i < n) {
                if (row.charAt(i) >= '0' && row.charAt(i) <= '9') {
                    StringBuilder cur = new StringBuilder();
                    int j = 0;
                    while (i + j < n && row.charAt(i + j) >= '0' && row.charAt(i + j) <= '9') {
                        cur.append(row.charAt(i + j));
                        j++;
                    }

                    if (check(mat, row, i, r)) {
                        ans += Integer.parseInt(cur.toString());
                    }

                    i += j;
                } else {
                    i++;
                }
            }

            r++;

        }

        return ans;
    }

    private static boolean check2(ArrayList<String> mat, String row, String cur, Map<Pair, ArrayList<Integer>> m, int x, int y) {
        while (x < row.length() && row.charAt(x) >= '0' && row.charAt(x) <= '9') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nx = x + i - 1;
                    int ny = y + j - 1;

                    if (nx < row.length() && nx >= 0 && ny < mat.size() && ny >= 0) {
                        char c = mat.get(ny).charAt(nx);
                        if (c == '*' && !m.get(new Pair(ny, nx)).contains(Integer.parseInt(cur))) {
                            m.get(new Pair(ny, nx)).add(Integer.parseInt(cur));
                        }
                    }
                }
            }
            
            x++;
        }

        return false;
    }
    
    private static long part2(ArrayList<String> mat) {
        long ans = 0;
    
        Map<Pair, ArrayList<Integer>> m = new HashMap<>();
    
        for (int i = 0; i < mat.size(); i++) {
            String row = mat.get(i);
            for (int j = 0; j < row.length(); j++) {
                if (row.charAt(j) == '*') {
                    m.put(new Pair(i, j), new ArrayList<>());
                }
            }
        }
    
        for (int r = 0; r < mat.size(); r++) {
            String row = mat.get(r);
            for (int i = 0; i < row.length(); i++) {
                if (Character.isDigit(row.charAt(i))) {
                    StringBuilder cur = new StringBuilder();
                    int j = i;
                    while (j < row.length() && Character.isDigit(row.charAt(j))) {
                        cur.append(row.charAt(j));
                        j++;
                    }
    
                    check2(mat, row, cur.toString(), m, i, r);
                    i = j - 1;
                }
            }
        }
    
        for (ArrayList<Integer> val : m.values()) {
            if (val.size() == 2) {
                int prod = 1;
                for (Integer x : val) {
                    prod *= x;
                }
                ans += prod;
            }
        }
    
        return ans;
    } 
    
}
