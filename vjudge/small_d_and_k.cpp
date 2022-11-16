#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair

void dfs(int depth, int v, int k, ll &sum, vector<vector<int>> &adj, vector<bool> &vis) {
    if (depth == k) return; 
    vis[v] = true;
    for (auto &n : adj[v]) {
        if (!vis[n]) {
            vis[n] = true;
            sum += 1LL * n;
            dfs(depth + 1, n, k, sum, adj, vis);
        }
    }
}

int main() {
    int n; int m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a; int b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll q; cin >> q;
    vector<pair<int, int>> qs;

    for (ll i = 0; i < q; i++) {
        int x; int k; cin >> x >> k;
        qs.push_back(mp(x, k));
    }

    ll sum;

    for (ll i = 0; i < q; i++) {
        vector<bool> vis(n, false);
        sum = 1LL * qs[i].f;
        dfs(0, qs[i].f, qs[i].s, sum, adj, vis);
        cout << sum << endl;
    }
}