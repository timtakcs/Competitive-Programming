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

// int solve(int sum, vector<int> &dp, vector<int> &c) {
//     if (dp[sum] != -1) return dp[sum];
//     else {
//         ll x = 0;
//         for (int i = 0; i < c.size(); i++) {
//             if (sum - c[i] >= 0) x += solve(sum - c[i], dp, c);
//         }

//         x %= MOD;
//         dp[sum] = x;
//     }

//     return dp[sum];
// }

// int main() {
//     setIO();

//     int n, x; cin >> n >> x;
//     vector<int> c(n);
//     for (int i = 0; i < n; i++) cin >> c[i];
//     vector<int> dp(x + 1, -1);
//     dp[0] = 1;

//     cout << solve(x, dp, c) << endl;

// }

int main() {
    setIO();

    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(x + 1, -1);
    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        ll x = 0;
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) x += dp[i - c[j]];
        }
        x %= MOD;
        dp[i] = x;
    }

    cout << dp[x] << endl;
}