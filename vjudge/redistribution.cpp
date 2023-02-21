#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

int main() {
    setIO();

    int S; cin >> S;

    vector<int> dp(S + 1);

    for (int i = 0; i <= S; i++) {
        dp[i] = 0;
    }

    dp[0] = 1; dp[1] = dp[2] = 0;

    for (int i = 3; i <= S; i++) {
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD; 
    }

    cout << dp[S] << endl;

    return 0;
}