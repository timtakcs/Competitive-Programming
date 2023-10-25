#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int count(int sum, vector<int> &dp, vector<int> &c) {
    if (sum == 0) {
        return 0;
    }

    if (dp[sum] != INF) return dp[sum];

    for (int i = 0; i < c.size(); i++) {
        if (sum - c[i] >= 0) {
            dp[sum] = min(dp[sum], count(sum - c[i], dp, c) + 1);
        }
    } 

    return dp[sum];
}

int main() {
    setIO();

    int n, x; cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> dp(x + 1, INF);

    cout << count(x, dp, c) << endl;
}