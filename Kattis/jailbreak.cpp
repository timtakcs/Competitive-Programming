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
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

struct point {
    int x;
    int y;
};

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

int main() {
    setIO();

    int n, m; cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    vector<point> entries;
    vector<point> prisoners;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == j) continue;
            if (i == 0 || i == n-1 && (map[i][j] == '.' || map[i][j] == '#')) {
                point p;
                p.x = i;
                p.y = j;
                entries.push_back(p);
            }
            else {
                if (j == 0 || j == m-1 && (map[i][j] == '.' || map[i][j] == '#')) {
                    point p;
                    p.x = i;
                    p.y = j;
                    entries.push_back(p); 
                }
            }
        } 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '$') {
                point p;
                p.x = i;
                p.y = j;
                prisoners.push_back(p);
            }
        }
    }

    for (auto p: prisoners) {

    }
}