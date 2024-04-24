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

ll sum(ll n) {
    return (n * (n + 1)) / 2;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<ll> sizes;

        ll cur = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > q) {
                if (cur >= k) sizes.push_back(cur);
                cur = 0;
            } else cur++;
        }

        if (cur >= k) sizes.push_back(cur);

        ll ans = 0;

        for (int i = 0; i < sizes.size(); i++) {
            ans += sum(sizes[i] - k + 1);
        }

        cout << ans << endl;;
    }
}