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

bool is_possible(ll t, ll k, vector<ll> &a) {
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += k / a[i];
        if (ans >= t) break;
    }
 
    return ans >= t;
}
 
int binary_search(ll l, ll h, vector<ll> &a, ll t) {    
    ll ans = 0;
    while (l < h) {
        ll mid = (l + h) / 2;
        if (is_possible(t, mid, a)) {
            ans = mid;
            h = mid;
        } else {
            l = mid + 1;
        }
    }
 
    return ans;
}
 
int main() {
    setIO();
 
    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll lo = 0;
	ll hi = 1e18;
	
    cout << binary_search(lo, hi, a, t) << endl;
}