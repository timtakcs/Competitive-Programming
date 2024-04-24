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
        int n, m, k; cin >> n >> m >> k;

        int to_paint = 0;

        for (int i = 0; i < n/m; i++) {
            to_paint += m - 1;
        }

        n %= m;

        to_paint += max(0, n - 1);

        if (to_paint > k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
}