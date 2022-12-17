namespace problem_11 {
    public class problem11 {
        public class monkey {
            public int id;
            public Queue<long> items;
            public long level;
            public long factor;
            public int recipient1;
            public int recipient2;
            public long test;
            public string op;
            public long count;

            public monkey(int ID, Queue<long> itms, int recipient_1, int recipient_2, long fctr, long test, string opp) {
                this.id = ID;
                this.items = itms;
                this.recipient1 = recipient_1;
                this.recipient2 = recipient_2;
                this.factor = fctr;
                this.test = test;
                this.op = opp;
                this.level = itms.Peek();
                this.count = 0;
            }

            public void delta() {
                bool reset = false;
                if (factor == 99) {
                    factor = level;
                    reset = true;
                }
                if (op == "+") {
                    this.level = level + factor;
                }
                else {
                    this.level = level * factor;
                }

                if (reset) {
                    factor = 99;
                    reset = false;
                }
            }

            public int get_recipient() {
                if (this.level % this.test == 0) {
                    return this.recipient1;
                }
                else {
                    return this.recipient2;
                }
            }

            public void bored() {
                this.level = this.level / 3;
            }
        }

        public void driver() {
            List<string> lines = read_lines();

            List<monkey> monkeys = parse_monkeys(lines);

            for (int round = 0; round < 10000; round++) {
                for (int i = 0; i < monkeys.Count; i++) {
                    while (monkeys[i].items.Count != 0) {
                        monkeys[i].level = monkeys[i].items.Dequeue();
                        monkeys[i].delta();
                        // monkeys[i].bored();
                        int recipient = monkeys[i].get_recipient();
                        monkeys[recipient].items.Enqueue(monkeys[i].level);
                        monkeys[i].count++;
                    }
                }
            }

            foreach(monkey m in monkeys) {
                foreach (int item in m.items) {
                    Console.Write(item);
                    Console.Write(" ");
                }
                Console.WriteLine();
            }

            long first = 0;
            long second = 0;

            for (int k = 0; k < monkeys.Count; k++) {
                if (monkeys[k].count > first) {
                    second = first;
                    first = monkeys[k].count;
                }
            }

            Console.WriteLine(first * second);
        }


        List<monkey> parse_monkeys(List<string> lines) {
            List<monkey> monkeys = new List<monkey>();

            for (int i = 0; i < 4; i++) {
                List<string> id_line = tokenize(lines[i * 7]);
                int id = 1;
                Queue<long> items = new Queue<long>();

                List<string> line2 = tokenize(lines[i * 7 + 1]);
                for (int j = line2.Count - 1; j > 0; j--) {
                    if (line2[j] == "items:") break;
                    items.Enqueue(Convert.ToInt64(Int32.Parse(line2[j])));
                }
                items = new Queue<long>(items.Reverse());

                List<string> op_line = tokenize(lines[i*7 + 2]);
                string op = op_line[op_line.Count - 2];
                string bla = op_line[op_line.Count - 1];
                long factor;
                if (bla == "old") {
                    factor = 99;
                }
                else {
                    int int_factor = Int32.Parse(bla);
                    factor = Convert.ToInt64(int_factor);
                }

                List<string> test_line = tokenize(lines[i*7 + 3]);
                long test = Int32.Parse(test_line[test_line.Count - 1]);

                List<string> r1 = tokenize(lines[i*7 + 4]);
                int rec1 = Int32.Parse(r1[r1.Count - 1]);

                List<string> r2 = tokenize(lines[i*7 + 5]);
                int rec2 = Int32.Parse(r2[r2.Count - 1]); 

                monkey mnky = new monkey(id, items, rec1, rec2, factor, test, op);

                monkeys.Add(mnky);
            }

            return monkeys;
        }

        public List<string> read_lines() {
            List<string> lines = new List<string>();

            foreach (string line in System.IO.File.ReadLines("small.in")) {  
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