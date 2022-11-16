#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair 
using namespace std;

void bfs(pair<int, int> p, vector<vector<bool>> &vis, vector<vector<pair<int, int>>> &xx, vector<vector<pair<int, int>>>  &yy) {
    queue<pair<int, int>> q;
    q.push(p);

    while (!q.empty()) {
        pair<int, int> h = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        vector<pair<int, int>> xn = xx[x];
        vector<pair<int, int>> yn = yy[y];
        for (pair<int, int> &nx : xn) {
            int xp = nx.first;
            int yp = nx.second;
            if (!vis[xp][yp]) {
                vis[xp][yp] = true;
                q.push(nx);
            }
        }
        for (pair<int, int> &ny : yn) {
            int xv = ny.first;
            int yv = ny.second;
            if (!vis[xv][yv]) {
                vis[xv][yv] = true;
                q.push(ny);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> xx(n);
    vector<vector<pair<int, int>>> yy(n);
    vector<pair<int, int>> vs(n);
    int maxx = 0;
    int maxy = 0;
    for (int i = 0; i < n; i++) {
        int x; int y; cin >> x >> y;
        x--; y--;
        xx[x].push_back(mp(x, y));
        yy[y].push_back(mp(x, y));
        vs.push_back(mp(x, y));
        maxx = max(x, maxx);
        maxy = max(y, maxy);
    }

    int num = 0;
    vector<vector<bool>> vis(maxx, vector<bool>(maxy, false));

    for (int i = 0; i < vs.size(); i++) {
        pair<int, int> v = vs[i];
        int x = v.first;
        int y = v.second;
        if (!vis[x][y]){
            bfs(v, vis, xx, yy);
        }
        num++;
    }

    cout << num - 1 << endl;
} 