#include <iostream>
#include <bits/stdc++.h>
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

bool check(int i, int j, vector<string> &grid, int n, int m) {
    vector<pii> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    for (auto d: dirs) {
        if (i + d.f < n && i + d.f >= 0 && j + d.s < m && j + d.s >= 0) {
            if (grid[i + d.f][j + d.s] == 'E') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    setIO();

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (check(i, j, grid, n, m)) {
                grid[i][j] = 'E';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}