#include <iostream>
#include <bits/stdc++.h>
#include <queue>
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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<ll> dijkstra(int n, int src, vector<vector<pair<int, int>>> &adj) {
    
    vector<ll> dist(n, INT64_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (pq.size()) {
        auto cur = pq.top(); pq.pop();

        int v = cur.second;

        for (auto p: adj[v]) {
            int w = p.first;
            int u = p.second;

            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            } 
        }
    }

    return dist;
}

int main() {
    setIO();

    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<pair<int, int>>> reverse_adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a - 1].push_back({w, b - 1});
        reverse_adj[b - 1].push_back({w, a - 1});
    }

    vector<ll> forward = dijkstra(n, 0, adj);
    vector<ll> backward = dijkstra(n, n - 1, reverse_adj);
    
    ll mn = INT64_MAX;

    for (int v = 0; v < n; v++) {
        for (auto e: adj[v]) {
            int u = e.second;
            int w = e.first;
            if (forward[v] == INT64_MAX || backward[u] == INT64_MAX) continue; // the nodes arent reachable from 1 or n

            mn = min(mn, forward[v] + (w / 2) + backward[u]);
        }
    }

    cout << mn << endl;
}