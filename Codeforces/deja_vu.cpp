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
        int n, q; cin >> n >> q;

        vector<ll> a(n);
        vector<int> x;
        vector<bool> vis(31, false);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < q; i++) {
            int k; cin >> k;
            if (!vis[k]) {
                x.push_back(k);
                vis[k] = true;
            }
        }

        int k = x.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                ll d = pow(2, x[j]);
                if (a[i] % d == 0) a[i] += (d / 2);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}