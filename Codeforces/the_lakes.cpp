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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
} 

void bfs(vector<vector<int>> &a, vector<vector<bool>> &vis, int &maxi, int i, int j, vector<pair<int, int>> &help) {
    int total = 0;
    queue<pair<int, int>> q;
    q.push(mp(i, j));

    vis[i][j] = true;

    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.f, y = curr.s;

        total += a[x][y];
    
        // cout << "current square" << a[x][y] << endl;

        for (auto p: help) {
            int nx = x + p.f, ny = y + p.s;

            if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size() && !vis[nx][ny] && a[nx][ny] > 0) {
                // cout << "pushing" << nx << " " << ny << endl;
                q.push(mp(nx, ny));
                vis[nx][ny] = true;
            }
        }

        
    }

    maxi = max(maxi, total);
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<pair<int, int>> help = {mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0)};

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && a[i][j] > 0) {
                    // cout << "running bfs from" << i << " " << j << " " << a[i][j] << endl;
                    bfs(a, vis, maxi, i, j, help);
                }
            }
        }

        cout << maxi << endl;
    }
}