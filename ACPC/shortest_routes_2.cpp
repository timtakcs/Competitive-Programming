#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr ll INF = 1e14;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
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

int main() {
    setIO();

    int n, m, q; cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        dist[a-1][b-1] = min(dist[a-1][b-1], (ll)w); 
        dist[b-1][a-1] = min(dist[b-1][a-1], (ll)w);

        dist[a-1][a-1] = 0; dist[b-1][b-1] = 0;
    }

    floyd_warshall(adj, dist, n);

    while (q--) {
        int a, b; cin >> a >> b;

        ll d = dist[a-1][b-1];

        if (d == INF) d = -1;
        
        cout << d << endl;
    }
}