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

ll kadane(vector<ll> &a, ll n) {
    ll ans = 0;
    ll cur = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, cur);
        cur += a[i];
        if (cur < 0) {
            cur = 0;
        }
    }
    ans = max(ans, cur);
    return ans;
}

int mod(ll x, ll p) {
    if (x < 0) {
        x = abs(x) % p;
        if (x == 0) return 0;
        return p - x;
    } else {
        return x % p;
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll sum = kadane(a, n) % MOD;
        ll og = sum;

        for (int i = 0; i < k; i++) {
            sum *= 2;
            sum %= MOD;
        }

        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        cout << mod(sum - og, MOD) << endl;
    }
}