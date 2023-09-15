#include <iostream>
#include<bits/stdc++.h>
#include <queue>
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

int main() {
    setIO();

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> in_deg(n);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);

        in_deg[b - 1]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!in_deg[i]) q.push(i);
    }

    vector<int> ans;

    while (q.size()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (auto v: adj[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0) q.push(v);
        }
    }

    if (ans.size() != n) cout << "IMPOSSIBLE" << endl;
    else for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
    cout << endl;
}