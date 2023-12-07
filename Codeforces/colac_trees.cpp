#include <iostream>
#include <bits/stdc++.h>
#include <map>
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

void dfs(vector<bool> &vis, vector<vector<int>> &adj, map<pii, int> &ord, int v, int p) {
    vis[v] = true;
    bool add = false;
    for (auto u: adj[v]) {
        if (vis[u]) continue;

        if (ord[{v, u}] > 1) continue;
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        
        vector<vector<int>> adj(n, vector<int>());
        map<pii, int> order;
        vector<bool> vis(n, false);

        vector<int> dp(n);
        vector<int> id(n, -1);

        dp[1] = 1;
        id[1] = 0;

        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);

            order[{a, b}] = i;
        }
        dfs(vis, adj, order, 0, -1);

        int mx = 0;
        for (auto x: dp) mx = max(mx, x);

        cout << mx << endl;
    }
}