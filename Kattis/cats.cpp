#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

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

struct edge {
    int u;
    int v;
    int w;
};

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
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

bool comp(edge &e1, edge &e2) {
    return e1.w < e2.w;
}

void kruskal(vector<edge> &edges, vector<edge> &mst, vector<int> &link, vector<int> &size) {
    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i].u, link) != find(edges[i].v, link)) {
            unite(edges[i].u, edges[i].v, link, size);
            mst.push_back(edges[i]);
        }
    }
}

int get_sum_edges(vector<vector<pii>> &adj, int u, vector<bool> &vis) {
    int sum = 0;
    for (auto v: adj[u]) {
        if (!vis[v.f]) {
            vis[v.f] = true;
            sum += v.s;
            sum += get_sum_edges(adj, v.f, vis);
        }
    }

    return sum;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int m, c; cin >> m >> c;
        int num_edges = c * (c - 1) / 2;

        vector<edge> edges;

        for (int i = 0; i < num_edges; i++) {
            int u, v, w; cin >> u >> v >> w;
            edges.pb({u, v, w});
        }

        vector<int> link(c);
        vector<int> size(c);

        for (int i = 0; i < c; i++) {
            link[i] = i;
            size[i] = 1;
        }

        vector<edge> mst;
        kruskal(edges, mst, link, size);

        vector<vector<pii>> adj(c, vector<pii>());

        for (int i = 0; i < mst.size(); i++) {
            adj[mst[i].u].pb(mp(mst[i].v, mst[i].w));
            adj[mst[i].v].pb(mp(mst[i].u, mst[i].w));
        }

        vector<bool> vis(c, false);
        vis[0] = true;
        int sum = get_sum_edges(adj, 0, vis);

        if (sum + c <= m) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

}