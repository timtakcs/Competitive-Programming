#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(int col, int row, vector<vector<bool>> &vis, vector<string> &f, int n, int m) {
    queue<pair<int, int>> q;
    q.push(make_pair(col, row));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int c =  cur.first;
        int r = cur.second;
        vector<pair<int, int>> neighbors = {make_pair(c - 1, r), make_pair(c + 1, r), make_pair(c, r - 1), make_pair(c, r + 1)};
        for (auto &coord: neighbors) {
            int x = coord.first;
            int y = coord.second;
            if (x < 0 || y < 0 || x > n || y > m) continue;
            if (!vis[x][y] && f[x][y] == '.') {
                vis[x][y] = true;
                q.push(make_pair(x, y));
            }
        }
    }
}

int main() {
    int n; int m; cin >> n >> m;
    vector<string> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<vector<bool>> vis (n, vector<bool> (m, false));
    int num = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] == '.') {
                if (!vis[i][j]) {
                    bfs(i, j, vis, f, n - 1, m - 1);
                    num++;
                }
            }
        }
    }

    cout << num << endl;
}