#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;

        vector<ll> a(n);
        vector<ll> b(m);

        ll sumj = 0;
        ll sumg = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumj += a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            sumg += b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (k == 1) {
            if (a[0] >= b[m - 1]) cout << sumj << endl;
            else cout << sumj - a[0] + b[m - 1] << endl;
        } else if (k == 2) {
            if (a[0] < b[m - 1]) {
                sumj = sumj - a[0] + b[m - 1];
                sumj = sumj + b[0] - max(a[n - 1], b[m - 1]);
            }
            else sumj = sumj - a[n - 1] + b[0];

            cout << sumj << endl;
        } else {
            ll temp = sumj;

            if (a[0] < b[m - 1]) {
                sumj = sumj - a[0] + b[m - 1];
                temp = sumj;
                sumj = sumj + min(a[0], b[0]) - max(a[n - 1], b[m - 1]);
            } else sumj = sumj - a[n - 1] + b[0];

            if ((k - 2) % 2 == 1) cout << temp << endl;
            else cout << sumj << endl;
        }
    }
}