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
        int n; cin >> n;
        string s; cin >> s;

        int cnt = 0;

        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                pos.push_back(i);
            }
        } 

        bool possible = true;

        if (cnt % 2 == 1) {
            possible = false;
        } else {
            int adj = 0;
            for (int i = 1; i < pos.size(); i++) {
                if (pos[i] == pos[i - 1] + 1) {
                    adj++;
                }
            }

            if (cnt == 2 && adj == 1) {
                possible = false;
            }
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}