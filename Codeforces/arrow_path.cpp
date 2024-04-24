#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

bool bfs(pii src, pii dst, map<pii, vector<pii>> &adj, int n) {
    queue<pii> q;
    vector<vector<bool>> vis(2, vector<bool>(n, false));

    q.push(src);
    vis[src.first][src.second] = true; 

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        if (cur == dst) {
            return true;
        }

        for (pii n: adj[cur]) {
            if (!vis[n.first][n.second]) {
                q.push(n);
                vis[n.first][n.second] = true; 
            }
        }
    }
    return false;
}


int main() {
    setIO();
 
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string> m(2);
        cin >> m[0] >> m[1];
 
        map<pii, vector<pii>> adj;
 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                pii pair = {i, j};
                if (j + 1 < n && m[i][j + 1] == '>') adj[pair].push_back({i, j + 2});
                if (j - 1 >= 0 && m[i][j - 1] == '<') adj[pair].push_back({i, j - 2});
                if (m[!i][j] == '>') adj[pair].push_back({!i, j + 1});
                if (m[!i][j] == '<') adj[pair].push_back({!i, j - 1});
            }
        }
 
        if (bfs({0, 0}, {1, n - 1}, adj, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}