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

vector<int> find_swap(vector<int> &a, int m) {
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        b[i] = a[i];
    }

    sort(b.begin(), b.end());

    vector<int> ans;

    for (int i = 0; i < m; i++) {
        if (a[i] != b[i]) ans.push_back(i);
    }

    return ans;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        bool possible = true;

        int first = 0;
        int second = 0;

        vector<bool> sorted(n, false);

        for (int i = 0; i < n; i++) {
            vector<int> swaps = find_swap(mat[i], m);

            if (swaps.size() == 0) sorted[i] = true;
            else if (swaps.size() == 2) {
                if (first == 0 && second == 0) {
                    first = swaps[0];
                    second = swaps[1];
                } else if (swaps[0] != first || swaps[1] != second) {
                    possible = false;
                    break;
                }
            } else if (swaps.size() > 2) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << -1 << endl;
            continue;
        } else if (first == 0 && second == 0) {
            cout << "1 1" << endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!sorted[i]) continue;
            else {
                if (mat[i][first] != mat[i][second]) {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible) cout << -1 << endl;
        else cout << first + 1 << " " << second + 1 << endl;
    }
}