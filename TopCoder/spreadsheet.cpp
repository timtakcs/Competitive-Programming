#include <iostream>
#include <vector>
#include "math.h"
#include <map>
using namespace std;

class Spreadsheet {
public:
    string goRight(string column) {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string copy = column;
        map<char, int> let_num;
        map<int, char> num_let;

        int last = letters.length() - 1;
        bool all_z = true;

        for (int i = 0; i < letters.length(); i++) {
            let_num[letters[i]] = i;
            num_let[i] = letters[i];
        }

        for (int k = 0; k < column.length(); k++){
            if (column[k] != 'Z') all_z = false;
            break;
        }

        for (int j = column.length() - 1; j >= 0; j--) {
            int idx = let_num[column[j]];
            if (idx != last) {
                copy[j] = num_let[idx + 1];
                return copy; 
            } 
            else if (all_z && idx == last) {
                char a = 'A';
                for (int n = 0; n < column.length(); n++) {
                    copy[n] = a;
                }
                copy += a;
                return copy;
            }
            else {
                copy[j - 1] = num_let[let_num[column[j - 1]] + 1];
                copy[j] = 'A';
                return copy;
            }
        }
    }
};

int main() {
    Spreadsheet s;
    cout << s.goRight("WALTZ") << endl;
    return 0;
}