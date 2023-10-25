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

bool is_possible(ll x, vector<ll> &a, ll k) {
    ll ans = 0;
    ll cur = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > x) return false;
        if (cur + a[i] > x) {
            cur = 0;
            ans++;
        }
        cur += a[i];
    }

    if (cur > 0) ans++;

    return ans <= k;
}

ll binary_search(ll l, ll h, vector<ll> &a, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid, a, k)) {
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

    ll n, k; cin >> n >> k;

    vector<ll> a(n);
    ll mx = -INF;   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    ll l = 1;

    // cout << is_possible(7, a, k) << endl;

    cout << binary_search(l, 1e9, a, k) << endl;
}