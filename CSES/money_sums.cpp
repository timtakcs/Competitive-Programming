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

    ll n; cin >> n;
    vector<ll> a(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < total + 1; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]) {
                dp[i][j] = true;
            }
        }
    }

    vector<ll> ans;

    for (int i = 1; i < total + 1; i++) {
        if (dp[n][i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
}