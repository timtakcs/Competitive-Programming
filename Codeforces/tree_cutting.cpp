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

void compute_subtrees(vector<int> &dp, vector<vector<int>> &adj, int u, int p) {
    dp[u] = 1; 
    for (int v : adj[u]) {
        if (v == p) continue;
        compute_subtrees(dp, adj, v, u);
        dp[u] += dp[v];
    }
}

ll binary_search(ll l, ll h, vector<ll> &a, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

bool is_possible(vector<int> &dp, vector<vector<int>> &adj, int k) {
    int size = dp[0];


}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }

        vector<int> dp(n);

        compute_subtrees(dp, adj, 0, -1);
    }
}