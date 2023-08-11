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

vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// floodfill algo, very similar to union find but easier to implement with a matrix

void bfs(vector<string> &map, int r, int c, int rows, int cols, vector<vector<int>> &fill, int color) {
    queue<pii> q;
    q.push({r, c});
    fill[r][c] = color;

    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        for (auto &dir : dirs) {
            int new_r = curr.f + dir.f;
            int new_c = curr.s + dir.s;

            if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols) continue;

            if (map[new_r][new_c] == map[r][c]) {
                if (!fill[new_r][new_c]) {
                    q.push({new_r, new_c});
                    fill[new_r][new_c] = color;
                }
            }
        }
    }
}

int main() {
    setIO();

    int r, c; cin >> r >> c;
    vector<string> map(r);
    for (int i = 0; i < r; i++) {
        cin >> map[i];
    }

    vector<vector<int>> fill(r, vector<int>(c, 0));

    int color = 1;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!fill[i][j]) {
                bfs(map, i, j, r, c, fill, color);
                color++;
            }
        }
    }

    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;

        r1--; c1--; r2--; c2--;

        if (map[r1][c1] != map[r2][c2]) {
            cout << "neither" << endl;
        } else if (fill[r1][c1] == fill[r2][c2]) {
            if (map[r1][c1] == '0') {
                cout << "binary" << endl;
            } else {
                cout << "decimal" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }
}