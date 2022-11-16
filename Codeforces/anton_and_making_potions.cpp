#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int get_best(ll left, ll k, vector<ll> &d, vector<ll> &c) {
    int l = 0;
    int r = k;
    int m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (d[m] <= left) l = m;
        else r = m - 1;
    }
    return c[l];
}

int main() {
    ll n; ll m; ll k;
    ll x; ll s;

    int maxn = 1000000;

    vector<ll> a(maxn);
    vector<ll> b(maxn);
    vector<ll> c(maxn);
    vector<ll> d(maxn);


    cin >> n >> m >> k;
	cin >> x >> s;
	a[0] = x;
	b[0] = 0;
	c[0] = 0;
	d[0] = 0;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= k; i++) cin >> c[i];
	for (int i = 1; i <= k; i++) cin >> d[i];

    ll score = n * x;
    
    for (int i = 0; i <= m; i++) {
        ll left = s - b[i];
        if (left < 0) continue;
        score = min(score, (n - get_best(left, k, d, c)) * a[i]);
    }

    cout << score << endl;
}