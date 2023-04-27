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

vector<vector<int>> transpose(vector<vector<int>> &adj, int n) {
    vector<vector<int>> adjT(adj.size(), vector<int>());
    for (int i = 0; i < n;i ++) {
        for (int j = 0; j < adj[i].size(); j++) {
            adjT[adj[i][j]].push_back(i);
        }
    }

    return adjT;
}

void dfs(vector<vector<int>> &adj, int v, int n, vector<bool> &vis) {
    for (auto u: adj[v]) {
        if (!vis[u]) {
            vis[u] = true;
            dfs(adj, u, n, vis);
        }
    }
}

bool one_component_kusaraju(vector<vector<int>> &adj, int n) {
    vector<bool> vis_pre(n, false);
    vector<bool> vis_post(n, false);

    dfs(adj, 0, n, vis_pre);

    for (int i = 0; i < n; i++) {
        if (!vis_pre[i]) return false;
    }

    vector<vector<int>> adjT = transpose(adj, n);
    dfs(adjT, 0, n, vis_post);

    for (int i = 0; i < n; i++) {
        if (!vis_post[i]) return false;
    }
    
    return true;
}

int main() {
    setIO();

    int n = -1;
    int m = -1;

    cin >> n >> m;

    int t = 1;

    while(n != -1 && m != -1) {

        map<pair<int, int>, int> edge_order;
        vector<vector<int>> adj(n, vector<int>());
        vector<pair<int, int>> valid_edges;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            edge_order[mp(a, b)] = i;
        }

        if (one_component_kusaraju(adj, n)) {
            cout << "Case " << t << ": valid" << endl;
        } else {
            bool valid = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < adj[i].size(); j++) {
                    vector<vector<int>> adj2 = adj;
                    adj2[i].erase(adj2[i].begin() + j);
                    adj2[adj[i][j]].push_back(i);

                    if (one_component_kusaraju(adj2, n)) {
                        valid_edges.push_back(mp(i, adj[i][j]));
                        valid = true;
                    }
                }
                if (valid) break;
            }
            if (!valid) cout << "Case " << t << ": " << "invalid" << endl;
            else {
                pair<int, int> first_edge = valid_edges[0];
                for (int i = 0; i < valid_edges.size(); i++) {
                    if (edge_order[valid_edges[i]] < edge_order[first_edge]) {
                        first_edge = valid_edges[i];
                    }
                }
                cout << "Case " << t << ": " << first_edge.f << " " << first_edge.s << endl;
            }
        }

        t++;

        n = -1;
        m = -1;
        
        cin >> n >> m;
    }
}