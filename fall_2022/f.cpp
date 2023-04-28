#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"
#include <math.h>

void helper(int n, int m, vector<string> &r) {
    if (!(m % 2)) {
        cout << "NO" << endl;
        return;
    }

    int mid = (m - 1)/2;

    if (r[0][mid] != '#') {
        cout << "NO" << endl;
        return;
    }

    bool flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == mid && r[i][j] == '#') continue;
            else if (j == mid && r[i][j] != '#') {
                cout << "NO" << endl;
                flag = true;
                break;
            }
            else if (r[i][j] == '#') {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) cout << "YES" << endl;
}

int main() {
    int n; int m; cin >> n >> m;
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    helper(n, m, r);
}
