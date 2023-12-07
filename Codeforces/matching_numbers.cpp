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

        if (!(n & 1)) cout << "No" << endl;
        else {
            cout << "Yes" << endl;

            vector<pair<int, int>> ans;

            int cur = 2 * n;

            for (int i = 0; i < n / 2 + 1; i++) {
                ans.push_back({cur, 2 * i + 1});
                cur--;
            }

            for (int i = 0; i < n / 2; i++) {
                ans.push_back({cur, 2 * (i + 1)});
                cur--;
            }

            for (auto p: ans) {
                cout << p.first << " " << p.second << endl;
            }
        }
    }
}