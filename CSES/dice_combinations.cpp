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

int solve(int sum, vector<int> &dp) {
    if (dp[sum] != -1) return dp[sum];
    else {
        ll x = 0;
        for (int i = 1; i <= min(sum - 1, 6); i++) {
            x += solve(sum - i, dp);
            x %= MOD;
        }
        if (sum <= 6) x++;
        dp[sum] = x;
        return dp[sum];
    }
}

int main() {
    setIO();
    int sum; cin >> sum;
    vector<int> dp(sum + 1, -1);
    dp[1] = 1;
    cout << solve(sum, dp) << endl;
}