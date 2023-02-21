#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

int main() {
    int n, sum; cin >> n >> sum;
    vector<int> coins(n);

    vector<ll> dp(sum + 1);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i <= sum; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= sum; weight++) {
			if(weight - coins[i - 1] >= 0) {
				dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
			}
		}
	}

    cout << (dp[sum] == INF ? -1 : dp[sum]) << endl;
}