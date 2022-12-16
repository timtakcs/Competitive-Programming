namespace problem_10 {
    public class problem10 {   

        public void driver() {
            List<string> lines = read_lines();
            List<List<string>> rows = get_rows();
            
            int x = 1;
            int sum = 0;

            int row = 0;

            int cycle = 1;

            foreach (string line in lines) {
                List<string> tokens = tokenize(line);

                if (cycle % 40 == 0) {
                    row++;
                    cycle -= 40;
                }

                cycle++;

                if (x - 1 == cycle - 1 || (x == cycle - 1) || x + 1 == cycle - 1) {
                    rows[row][cycle - 1] = "#";
                }

                if (tokens[0] == "addx") {
                    if (cycle % 40 == 0) {
                        row++;
                        cycle -= 40;
                    }

                    x += Int32.Parse(tokens[1]);
                    cycle++;

                    if (x - 1 == cycle - 1 || (x == cycle - 1) || x + 1 == cycle - 1) {
                        rows[row][cycle - 1] = "#";
                    }
                }
            }

            print_display(rows);
        }

        public List<List<string>> get_rows() {
            List<List<string>> rows = new List<List<string>>();

            for (int i = 0; i < 6; i++) {
                List<string> row = new List<string>();

                for (int j = 0; j < 40; j++) {
                    row.Add(".");
                }

                rows.Add(row);
            }

            return rows;
        }

        void print_display(List<List<string>> rows) {
            foreach (List<string> row in rows) {
                foreach(string element in row) {
                    Console.Write(element);
                }
                Console.WriteLine();
            }
        }

        public List<string> read_lines() {
            List<string> lines = new List<string>();

            foreach (string line in System.IO.File.ReadLines("input.in")) {  
               lines.Add(line);
            }

            return lines;
        }

        public List<string> tokenize(string line) {
            List<string> tokens = new List<string>();

            string cur = "";

            foreach(char c in line) {
                if (c == ' ') {
                    tokens.Add(cur);
                    cur = "";
                }
                else {
                    cur += c;
                }
            }

            tokens.Add(cur);

            return tokens;
        }
    }
}