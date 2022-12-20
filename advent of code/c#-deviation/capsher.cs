namespace capsher_ {
    public class capsher {
        public void driver() {
            Console.WriteLine("hello world");

            // lmao that was so easy i could just do it in the browser
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