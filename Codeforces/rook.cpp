#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        string pos; cin >> pos;

        vector<string> ans;

        char file = pos[0];
        char rank = pos[1];

        for (int i = 1; i <= 8; i++) {
            if (i + '0' == rank) continue;
            string cur = "";

            cur += file;
            cur += i + '0';

            ans.push_back(cur);
        }

        for (char x = 'a'; x <= 'h'; x++) {
            if (x == file) continue;

            string cur = "";
            cur += x;
            cur += rank;

            ans.push_back(cur);
        }

        for (auto c: ans) {
            cout << c << endl;
        }
    }
}