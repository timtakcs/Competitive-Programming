#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int v, vector<bool> &vis, vector<int> &comp_lead, vector<vector<int>> &adj) {
    queue<int> q;
    q.push(v);
    comp_lead.push_back(v);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int &neighbor: adj[node]) {
            vis[neighbor] = true;
            q.push(neighbor);
        }
    }
}

void dfs(int v, vector<bool> &vis, vector<vector<int>> &adj) {
    vis[v] = true;
    for (int &neighbor : adj[v]) {
        if (!vis[neighbor]) {
            dfs(neighbor, vis, adj);
        }
    }
}

int main() {
    int m; int n; cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++){
        int a; int b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(1);
        adj[b].push_back(1);
    }

    int num = 0;
    vector<int> comp_lead;
    vector<bool> vis(n);
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            bfs(v, vis, comp_lead, adj);
        }
        num++;
    }

    cout << num - 1 << endl;

    for (int i = 0; i < comp_lead.size() - 1; i++) {
        cout << comp_lead[i] + 1 << " " << comp_lead[i + 1] + 1 << endl;
    }
}