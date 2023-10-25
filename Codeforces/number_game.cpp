#include <iostream>
#include<bits/stdc++.h>
#include <set>
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

bool is_possible(ll k, multiset<ll> a) {
    if (a.size() < k) return false;

    for (int i = 0; i < k; i++) {
        auto lb = a.upper_bound(k - i);
        if (lb == a.begin()) return false;
        
        if (i != k - 1) {
            a.erase(--lb);
            ll x = *a.begin();

            a.erase(a.begin());
            a.insert(x + k - i);
        }
    }

    return true;
}

ll binary_search(ll l, ll h, multiset<ll> &a) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid, a)) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}

int main() {
    setIO();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<ll> a;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            a.insert(x);
        }

        ll l = 0;
        ll h = n + 1;
        
        cout << binary_search(l, h, a) << endl;
    }
}
