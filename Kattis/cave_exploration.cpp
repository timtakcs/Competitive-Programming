#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void dfs_bridges(vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, int &t, vector<bool> &vis, int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = t++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs_bridges(adj, tin, low, t, vis, to, v);
            low[v] = min(low[v], low[to]);
        }
    }
}

void get_bridges(int n, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low) {
    tin[0] = 1;
    low[0] = 1;

    int t = 2;
    vector<bool> vis(n, false);
    set<int> bridges;

    dfs_bridges(adj, tin, low, t, vis, 0);

    for (int i = 1; i < n; i++) {
        if (tin[i] == low[i]) {
            bridges.insert(i);
        }
    }

    vector<bool> new_vis(n, false);
    queue<int> q;
    q.push(0);
    new_vis[0] = true;

    while(q.size()) {
        int cur = q.front(); q.pop();
        for (int to : adj[cur]) {
            if (!bridges.count(to) && !new_vis[to]) {
                new_vis[to] = true;
                q.push(to);
            }
        }
    }

    int count = 0;
    for (auto v: new_vis) {
        if (v) {
            count++;
        }
    }

    cout << count << endl;

}

int main() {
    setIO();
    
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> tin(n);
    vector<int> low(n);
    int t = 0;
    
    get_bridges(n, adj, tin, low);
}