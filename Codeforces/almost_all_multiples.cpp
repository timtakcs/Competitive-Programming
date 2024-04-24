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

void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;

        vector<vector<int>> mult(n + 1, vector<int>(0));
        vector<bool> vis(n + 1, false);

        for (int i = 2; i <= n; i++) {
            int k = 1;
            while (i * k <= n) {
                mult[i].push_back(i * k);
                k++;
            }
        }

        for (auto x: mult) {
            for (auto z: x) {
                cout << z << " ";
            }
            cout << endl;
        }

        vector<int> ans;
        ans.push_back(x);
        vis[x] = true;

        bool possible = true;

        for (int i = 2; i < n; i++) {
            int j = 0;
            while (j < mult[i].size() && vis[mult[i][j]]) {
                j++;
            }

            if (j >= mult[i].size()) {
                possible = false;
                break;
            } else {
                ans.push_back(mult[i][j]);
                vis[mult[i][j]] = true;
            }
        }

        // print_vector(ans);

        ans.push_back(1);

        if (possible) print_vector(ans);
        else cout << -1 << endl;
    }

}