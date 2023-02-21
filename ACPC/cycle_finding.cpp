#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr ll INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void cycle_bellman_ford(vector<vector<int>> &edges, vector<ll> &dist, int n, int m) {
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

    if (!cycle) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            x = p[x];
        }
        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }

        reverse(cycle.begin(), cycle.end());

        for(auto node: cycle) {
            cout << node + 1 << " ";
        }
    }
}

int main() {
    setIO();

    int n, m; cin >> n >> m;

    vector<vector<int>> edges(m);
    vector<ll> dist(n);

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[i] = {a-1, b-1, w};
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[0] = 0;

    cycle_bellman_ford(edges, dist, n, m);
}
