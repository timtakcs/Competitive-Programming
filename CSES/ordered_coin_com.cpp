#include <iostream>
#include<bits/stdc++.h>
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

    int n, x; cin >> n >> x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<ll> dp(x + 1);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - c[i] >= 0) {
                dp[j] += dp[j - c[i]];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[x] << endl;
}