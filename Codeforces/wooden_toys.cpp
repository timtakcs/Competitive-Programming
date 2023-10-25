#include <iostream>
#include<bits/stdc++.h>
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

bool is_possible(ll k, vector<ll> &a) {
    ll cur = a[0];
    ll ans = 1;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if ((a[i] - cur + 1) / 2 > k) {
            ans++;
            cur = a[i];
        }
    }

    return ans <= 3;
}

ll binary_search(ll l, ll h, vector<ll> &a) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid, a)) {
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        ll l = 0;
        ll h = a[n - 1] - a[0] + 1;

        cout << binary_search(l, h, a) << endl;
    }
}