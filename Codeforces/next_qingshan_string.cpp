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

        vector<int> ops;

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (s[l] == s[r]) {
                if (s[l] == '0') {
                    ops.push_back(r);
                    s.insert(s.begin() + r + 1, '0');
                    s.insert(s.begin() + r + 2, '1');

                    r += 2;
                } else {
                    ops.push_back(l);
                    s.insert(s.begin() + l, '1');
                    s.insert(s.begin() + l + 1, '0');
                    
                    r += 2;
                    l++;
                }
            } else {
                l++; r--;
            }

            if (ops.size() > 300) break;
        }

        if (ops.size() <= 300) {
            cout << ops.size() << endl;
            for (auto x: ops) cout << x + 1 << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}