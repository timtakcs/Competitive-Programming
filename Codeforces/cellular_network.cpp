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

bool is_possible(ll k, vector<ll> &a, vector<ll> &b) {
    int l = 0;
    int r = 0;

    while (l < a.size() && r < b.size()) {
        if (abs(a[l] - b[r]) <= k) {
            l++;
        } else {
            r++;
        }
    }

    return l == a.size();
}

ll binary_search(ll l, ll h, vector<ll> &a, vector<ll> &b) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid, a, b)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    setIO();

    // using two pointers, one for the towers and one for towns, increment towns if it is still in range, 
    // otherwise increment the towers pointer to check if a certain r is possible. 
    // Then binary search for the lowest r.

    int n, m; cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    ll mx = -INF;
    ll mn = INF;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mx = max(mx, b[i]);
        mn = min(mn, b[i]);
    }

    cout << binary_search(0, abs(mx - mn), a, b) << endl;
}