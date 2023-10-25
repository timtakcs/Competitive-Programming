#include <iostream>
#include<bits/stdc++.h>
#include <queue>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
    }

    vector<bool> vis(n, false);
    vector<int> s;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<int> q;

            q.push(i);
            s.push_back(i);

            while (q.size()) {
                int cur = q.front(); q.pop();
                for (auto u: adj[i]) {
                    if (!vis[u]) {
                        vis[u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }

    if (s.size() == 1) cout << "YES" << endl;
    else {
        cout << "NO" << endl;
        for (auto x: s) cout << x + 1 << " ";
    }
}