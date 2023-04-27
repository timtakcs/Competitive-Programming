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

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// template code above to avoid red lines in the algos

// -------------------
// SHORTEST PATH
// -------------------

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

// ------------------------
// BASICS
// ------------------------

void bfs(vector<vector<int>> &adj, int src, int n) {
    queue<int> q;
    vector<bool> vis(n, false);

    q.push(src);
    vis[src] = true;

    while (q.size()) {
        int u = q.front(); q.pop();

        for (auto n: adj[u]) {
            if (!vis[n]) {
                vis[n] = true;
                q.push(n);        
            }
        }
    }
}

void dfs(vector<vector<int>> &adj, int v, int n, vector<bool> &vis) {
    for (auto u: adj[v]) {
        if (!vis[u]) {
            vis[u] = true;
            dfs(adj, u, n, vis);
        }
    }
}

// ------------------------
// BRIDGES AND ARTICULATION POINTS
// ------------------------

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

// ------------------------
// TOPOLOGICAL SORTING
// ------------------------

bool check_cycle(vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s, vector<int> &ans, int v, int n) {
    unordered_map<int, int> pos;
    int index = 0;

    while (!s.empty()) {
        pos[s.top()] = index;

        ans.push_back(s.top());
 
        index++;
        s.pop();
    }
 
    for (int x = 0; x < n; x++) {
        for (auto u: adj[x]) {
            if (pos[x] > pos[u]) {
                return true;
            }
        }
    }

    return false;
}

void topo_dfs(vector<vector<int>> &adj, int v, int n, vector<bool> &vis, stack<int> &s) {
    for (auto u: adj[v]) {
        if (!vis[u]) {
            vis[u] = true;
            topo_dfs(adj, u, n, vis, s);
        }
    }
    s.push(v);
}

// Kahn's Algorithm

vector<int> kahn(vector<vector<int>> &adj, int n, vector<int> &in_deg) {
    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (q.size()) {
        int u = q.front(); q.pop();
        ans.push_back(u);

        for (auto v: adj[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    return ans;
}

// ------------------------
// PATH COMPRESSION UNION FIND
// ------------------------

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    if (size[a] > size[b]) {
        swap(a, b);
    } 
    link[b] = a;
    size[a] += size[b];                       
}