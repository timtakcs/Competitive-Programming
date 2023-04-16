#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
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

bool has_bridge(int n, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low) {
    tin[0] = 1;
    low[0] = 1;

    int t = 2;
    vector<bool> vis(n, false);

    dfs_bridges(adj, tin, low, t, vis, 0);

    for (int i = 1; i < n; i++) {
        if (tin[i] == low[i]) {
            return true;
        }
    }
    return false;
}

int find(int x, map<int, int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(int a, int b, map<int, int> &link, map<int, int> &size) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    if (size[a] > size[b]) {
        size[a] += size[b];
        link[b] = a;
    } else {
        size[b] += size[a];
        link[a] = b;
    }
}

int main() {
    setIO();
    
    int n, m; cin >> n >> m;

    while (n != 0 && m != 0) {
        vector<vector<int>> adj(n);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        map<int, int> size;
        map<int, int> link;

        for (int i = 0; i < n; i++) {
            link[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);

            unite(a, b, link, size);
        }

        bool connected = true;

        for (int i = 1; i < n; i++) {
            if (find(0, link) != find(i, link)) {
                connected = false;
                break;
            }
        }

        int t = 0;

        if (has_bridge(n, adj, tin, low) || !connected) cout << "Yes" << endl;
        else cout << "No" << endl;

        cin >> n >> m;
    }
    
}