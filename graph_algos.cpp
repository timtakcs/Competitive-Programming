#include "graph_algos.h"

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

bool cycle_bellman_ford(vector<vector<int>> &edges, vector<ll> &dist, int n, int m) {
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u, v, w;
            u = edges[j][0];
            v = edges[j][1];
            w = edges[j][2];

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                p[v] = u;
            }
        }
    }

    bool cycle = false;

    int x;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        if (dist[u] + w < dist[v]) {
            cycle = true;
            x = u;
            break;
        }
    }

    return cycle;
}

void floyd_warshall(vector<vector<pair<int, int>>> &adj, vector<vector<ll>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}