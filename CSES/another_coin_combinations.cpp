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

int solve(int i, int sum, vector<int> &dp, vector<int> &c) {
    if (dp[])
}

int main() {
    setIO();

    int n, x; cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> dp(x + 1);
    dp[0] = 1;
}