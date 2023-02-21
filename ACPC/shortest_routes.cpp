#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr ll INF = LLONG_MAX;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void dijkstra(int v, vector<vector<pair<ll, int>>> &adj, vector<ll> &dist, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(mp(v, 0));

    vector<bool> vis(n, false);

    while (q.size()) {
        pair<int, ll> cur = q.top();
        q.pop();

        int u = cur.s;

        if (vis[u]) continue;
        vis[u] = true;

        for (auto new_node: adj[u]) {
            int n = new_node.s;
            int w = new_node.f;
            if (dist[u] + w < dist[n]) {
                dist[n] = dist[u] + w;
                q.push(mp(dist[n], n));
            }
        }
    }
}

int main() {
    setIO();

    int n, m; cin >> n >> m;

    vector<vector<pair<ll, int>>> adj(n);
    vector<ll> dist(n, INF);

    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        ll w; cin >> w;
        adj[a-1].push_back(mp(w, b-1));
    }

    dist[0] = 0;
    
    dijkstra(0, adj, dist, n);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}