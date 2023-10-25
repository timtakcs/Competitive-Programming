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

bool is_possible(ll k, ll x, vector<ll> &a) {
    int n = a.size();
    int mid = n / 2;
    ll num_ops = 0;

    for (int i = mid; i < n; i++) {
        num_ops += max((ll)0, x - a[i]);
    }

    return num_ops <= k;
}

int main() {
    setIO();

    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    ll l = a[n / 2] - 1;
    ll h = a[n - 1] + k + 1;
    ll ans = -1;

    while (l < h) {
        ll mid = (h + l) / 2;
        if (is_possible(k, mid, a)){
            ans = mid;
            l = mid + 1;
        }
        else h = mid;
    }

    cout << ans << endl;
}