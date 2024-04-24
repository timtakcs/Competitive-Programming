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

bool check(vector<vector<int>> &a, vector<int> &ans, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ans[i] | ans[j]) != a[i][j]) return false;
        }
    } 
    return true;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        vector<int> ans(n, pow(2, 30) - 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                else {
                    ans[i] &= a[i][j];
                    ans[j] &= a[i][j];
                }
            }
        }

        if (check(a, ans, n)) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }    
}