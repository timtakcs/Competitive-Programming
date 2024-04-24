#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b;
        vector<int> c;

        b.push_back(INF);
        c.push_back(INF);

        for (int i = 0; i < n; i++) {
            if (a[i] <= b.back()) {
                b.push_back(a[i]);
            } else if (a[i] <= c.back()) {
                c.push_back(a[i]);
            } else {
                if (b.back() >= c.back()) {
                    b.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < b.size() - 1; i++) {
            if (b[i] < b[i + 1]) ans++;
        }

        for (int i = 0; i < c.size() - 1; i++) {
            if (c[i] < c[i + 1]) ans++;
        }

        cout << ans << endl;
    }
}

// 4 6 1 2 3 - [6, 1, 2] [4, 3] ans = 1
// 2 3 4 5 1 - [2, 1] [3, 4, 5] ans = 2
// 4 5 3 2 1 - [4] [5, 3, 2, 1] ans = 0