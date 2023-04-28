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

set<int> bfs(vector<vector<int>> &adj, int src, int n) {
    queue<pair<int, int>> q;
    vector<bool> vis(1006, false);

    set<int> possible;

    q.push({src, 0});
    vis[src] = true;

    while (q.size()) {
        pair<int, int> cur = q.front(); q.pop();
        int u = cur.f;
        int d = cur.s;

        if (d <= 3) {
            possible.insert(u);
        } else {
            continue;
        }

        for (auto n: adj[u]) {
            if (!vis[n]) {
                vis[n] = true;
                q.push({n, d+1});        
            }
        }
    }

    return possible;
}

int main() {
    setIO();

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(1006, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    set<int> possible = bfs(adj, 0, n);

    possible.erase(0);

    cout << possible.size() << endl;

    for (auto v: possible) {
        cout << v << " ";
    }
}