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

bool check(string s, int n, int m) {

    vector<pii> difs = {{1, 0}, {-1, 0}, {0, 1}, {-1, 1}, {1, 1}};
    vector<vector<char>> mat(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = s[m * i + j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] != 'T') continue;
            
            for (auto d: difs) {
                int dx = i + d.first;
                int dy = j + d.second;

                if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    if (mat[i][j] == mat[dx][dy]) {
                        return false;
                    }
                }
            }   
        }
    }

    return true;
}

int main() {
    setIO();

    string s; cin >> s;
    vector<string> ans;

    int size = s.length();

    for (int m = 1; m <= sqrt(size); m++) {
        if (size % m != 0) continue;

        int n = size / m;

        if (check(s, n, m)) {
            ans.push_back(to_string(n) + "x" + to_string(m));
        }

        if (n != m && check(s, m, n)) {
            ans.push_back(to_string(m) + "x" + to_string(n));
        }
        
    }

    cout << ans.size() << endl;
    for (auto x: ans) {
        cout << x << endl;
    }
}