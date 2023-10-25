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
        int n, p; cin >> n >> p;
        vector<int> a(n); vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int, int>> c;
        for (int i = 0; i < n; i++) c.push_back({b[i], a[i]});

        ll ans = 0;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            if (cur == n) break;

            if (c[i].f <= p && c[i + 1].f >= p) {
                ans += (n - cur) * p;
            } else {
                int num = min(n - cur, c[i].s);
                ans += num * c[i].f;
                cur += num;
            }
        }

        cout << ans << endl;
    }    
}