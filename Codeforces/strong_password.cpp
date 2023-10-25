#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

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
        string s; cin >> s;
        int m; cin >> m;
        string l, r; cin >> l >> r;

        int last = 0;
        int n = s.size();

        bool valid = false;

        for (int b = 0; b < m; b++) {
            int lb = l[b] - '0';
            int rb = r[b] - '0';

            vector<bool> found(10, false);
            int new_last = 0;

            for (int i = last; i < n; i++) {
                int cur = s[i] - '0';

                if (cur <= rb && cur >= lb) {
                    found[cur] = true;
                    new_last = i;
                }
            }

            for (int i = lb; i <= rb; i++) {
                if (!found[i]) valid = true;
            }

            if (valid) break;

            last = new_last;
        }

        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}