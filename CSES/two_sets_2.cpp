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

    int n; cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    sum /= 2;

    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            if (j - i >= 0) {
                dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= MOD;
            }
        }
    } 

    cout << dp[n][sum] << endl;
}
