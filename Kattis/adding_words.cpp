#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

vector<string> tokenize(string &line) {
    vector<string> res;
    string cur = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            res.push_back(cur);
            cur = "";
        }
        else {
            cur += line[i];
            continue;
        }
    }

    res.push_back(cur);

    return res;
}

int main() {
    setIO();

    string line;

    map<string, int> s;
    map<int, string> m;

    while(getline(cin, line)) {
        if (line.empty()) break;

        vector<string> tokens = tokenize(line);

        bool valid;

        if (tokens[0] == "def") {
            s[tokens[1]] = stoi(tokens[2]);
            m[stoi(tokens[2])] = tokens[1];

            // for (auto i : s) {
            //     cout << i.first << " " << i.second << endl;
            // }

        } else if (tokens[0] == "calc") {
            int factor = 1;
            int sum = 0;
            valid = true;
            for (int i = 1; i < tokens.size(); i++) {
                if (tokens[i] == "+") factor = 1;
                else if (tokens[i] == "=") continue;
                else if (tokens[i] == "-") factor = -1;
                else  {
                    if(s.count(tokens[i])) sum += factor * s[tokens[i]];
                    else {
                        valid = false;
                        break;
                    }
                }
            }

            string out_sum;

            if (valid && m.count(sum)) {
                out_sum = m[sum];   
            } else {
                out_sum = "unknown";
            }
            for (int j = 1; j < tokens.size(); j++) {
                cout << tokens[j] << " ";
            }
            cout << out_sum << endl;
        } else {
            s.clear();
            m.clear();
        }
    }

}