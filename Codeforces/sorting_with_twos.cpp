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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans;
        for (int i = 2; i < n; i++) {
            if (a[i] < a[i - 1]) ans.push_back(i + 1);
        }

        // for (auto x: ans) cout << x << " ";
        // cout << endl;

        bool pos = true;
        for (auto x: ans) {
            if (!(x == 3 || x == 5 || x == 9 || x == 17)) {
                pos = false;
                break;
            }
        }

        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}