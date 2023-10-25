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
        double n, m; cin >> n >> m;

        double split = n / m;

        if (split == 0.2) continue;

        int ans = 0;
        double i = 1;

        while (split != 0) {
            ans += floor(split / (1/i)) * floor(i / 2);
            split -= floor(split / (1/i)) * (1/i);
            i *= 2;

            // cout << split << "  ";
        }

        cout << ans << endl;
    }
}