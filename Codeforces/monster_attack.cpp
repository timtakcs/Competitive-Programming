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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<ll> a(n);
        vector<ll> x(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        vector<ll> sum(n + 1);

        for (int i = 0; i < n; i++) {
            ll dist = abs(x[i]);

            sum[dist] += a[i];
        }

        ll over = 0;
        bool possible = true;

        for (int i = 1; i <= n; i++) {
            if (sum[i] > k + over) {
                possible = false;
                break;
            } else {
                over = k + over - sum[i];
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}