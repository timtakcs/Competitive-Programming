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
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void bfs(vector<vector<int>> &adj, int src, int n, vector<int> &level) {
    queue<pair<int, int>> q;
    vector<bool> vis(n, false);

    q.push(mp(src, 0));
    vis[src] = true;

    while (q.size()) {
        pair<int, int> cur = q.front(); q.pop();

        int u = cur.f;
        int k = cur.s;

        level[u] = k;

        for (auto n: adj[u]) {
            if (!vis[n]) {
                vis[n] = true;
                q.push(mp(n, k+1));        
            }
        }
    }
}

int main() {
    setIO();
    ifstream fin ("testcase.in");

    // int n; cin >> n;
    int n; fin >> n;
    vector<vector<int>> adj(n);
    vector<int> level(n, -1);

    for (int i = 0; i < n - 1; i++) {
        // int a, b; cin >> a >> b;
        int a, b; fin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    bfs(adj, 0, n, level);

    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        // cin >> t[i];
        fin >> t[i];
    }

    if (level[t[0]-1] != 0) cout << "No" << endl;
    else {
        int prev = 1;
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (level[t[i] - 1] < prev) {
                cout << "No" << endl;
                valid = false;
                break;
            } else {
                prev = level[t[i] - 1];
            }
        }
        if (valid) cout << "Yes" << endl;
    }
}
