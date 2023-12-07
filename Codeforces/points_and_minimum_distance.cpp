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
        vector<int> a(2*n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<pair<int, int>> ans;
        int len = 0;

        ans.push_back({a[0], a[2 * n - 1]});

        for (int i = 1; i < n; i++) {
            len += abs(a[i] - ans[i - 1].f) + abs(a[2*n - i - 1] - ans[i - 1].s);
            ans.push_back({a[i], a[2 * n - i - 1]});
        }

        cout << len << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i].f << " " << ans[i].s << endl;
        }
    }
}