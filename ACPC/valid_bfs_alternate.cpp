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

vector<int> ord(200001);

bool bfs(vector<vector<int>> &adj, int src, int n, vector<int> &a) {
    queue<int> q;
    vector<bool> vis(n, false);

    int idx = 1;

    q.push(src);
    vis[src] = true;

    while (q.size()) {
        int u = q.front(); q.pop();

        for (auto n: adj[u]) {
            if (!vis[n]) {
                if (a[idx]-1 != n) return false;
                vis[n] = true;
                q.push(n);      
                idx++;  
            }
        }
    }

    return idx == n;
}

bool cmp(int a, int b) {
    return ord[a] < ord[b];
}

int main() {
    setIO();
    // ifstream fin ("testcase.in");

    int n; cin >> n;
    // int n; fin >> n;
    vector<vector<int>> adj(n);
    vector<int> a(n);

    for (int i = 0; i < n - 1; i++) {
        // int a, b; cin >> a >> b;
        int a, b; cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ord[a[i]-1] = i;
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }

    if (bfs(adj, 0, n, a)) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;

}