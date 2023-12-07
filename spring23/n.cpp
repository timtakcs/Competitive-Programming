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

int is_connected(vector<string> &m, vector<vector<int>> &has_water, int n, int i, int j) {
    int cnt = 0;

    if (m[i][j] == '\\') {
        if (i > 0) {
            if (j > 0 && m[i - 1][j - 1] == '\\' && has_water[i - 1][j - 1]) has_water[i][j] = 1; cnt++;
            if (m[i - 1][j] == '/' && has_water[i - 1][j]) has_water[i][j] = 1; cnt++;
        } if (i < n - 1) {
            if (j < n - 1 && m[i + 1][j + 1] == '\\' && has_water[i + 1][j + 1]) has_water[i][j] = 1; cnt++;
            if (m[i + 1][j] == '/' && has_water[i + 1][j]) has_water[i][j] = 1; cnt++;
        } if (j > 0) {
            if (m[i][j - 1] == '/' && has_water[i][j - 1]) has_water[i][j] = 1; cnt++;
        } if (j < n - 1) {
            if (m[i][j + 1] == '/' && has_water[i][j + 1]) has_water[i][j] = 1; cnt++;
        }
    } else if (m[i][j] == '/') {
        if (i > 0) {
            if (j < n - 1 && m[i - 1][j + 1] == '/' && has_water[i - 1][j + 1]) has_water[i][j] = 1; cnt++;
            if (m[i - 1][j] == '\\' && has_water[i - 1][j]) has_water[i][j] = 1; cnt++;
        } if (i < n - 1) {
            if (j > 0 && m[i + 1][j - 1] == '/' && has_water[i + 1][j - 1]) has_water[i][j] = 1; cnt++;
            if (m[i + 1][j] == '\\' && has_water[i + 1][j]) has_water[i][j] = 1; cnt++;
        } if (j > 0) {
            if (m[i][j - 1] == '\\' && has_water[i][j - 1]) has_water[i][j] = 1; cnt++;
        } if (j < n - 1) {
            if (m[i][j + 1] == '\\' && has_water[i][j + 1]) has_water[i][j] = 1; cnt++;
        }
    }

    return cnt;
}

void set_water(vector<string> &m, vector<vector<int>> &has_water, int n) {
    has_water[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (has_water[i][j]) continue;

            is_connected(m, has_water, n, i, j);
        }
    }
}

int main() {
    setIO();

    int n; cin >> n;
    vector<string> m(n);
    for (int i = 0; i < n; i++) cin >> m[i];
    vector<vector<int>> has_water(n, vector<int>(n, 0));

    vector<pii> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '?') {
                if (i == 0 && j == 0) {
                    m[i][j] = '\\';
                } else {
                    c.push_back({i, j});
                }
            }
        }
    }

    for (int i = 0; i < c.size(); i++) {
        set_water(m, has_water, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << has_water[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        int x = c[i].f;
        int y = c[i].s;

        m[x][y] = '\\';
        int first = is_connected(m, has_water, n, x, y);

        m[x][y] = '/';
        int second = is_connected(m, has_water, n, x, y);

        // cout << first << " " << second << " " << x << " " << y << endl;

        if (first > second) {
            m[x][y] = '\\';
        } else {
            m[x][y] = '/';
        }
    }

    for (int i = 0; i < n; i++) {
        cout << m[i] << endl;
    }
}