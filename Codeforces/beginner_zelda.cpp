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

int total = 0;

void dfs(vector<vector<int>> &adj, int p, int v) {
    if (adj[v].size() == 1) total++;
    for (int u: adj[v]) {
        if (u != p) {
            dfs(adj, v, u);
        }
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }

        total = 0;

        dfs(adj, -1, 0);

        cout << (total + 1) / 2 << endl;
    }
}