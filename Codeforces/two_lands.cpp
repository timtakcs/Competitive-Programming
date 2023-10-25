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

bool is_possible(vector<ll> &a, ll l, ll r) {
    return min(abs(a[l] + a[r]), abs(a[l] - a[r])) <= min(abs(a[l]), abs(a[r])) &&
            max(abs(a[l] + a[r]), abs(a[l] - a[r])) >= max(abs(a[l]), abs(a[r]));
}

ll lower_binary_search(ll l, ll h, vector<ll> &a, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(a, k, mid)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

ll upper_binary_search(ll l, ll h, vector<ll> &a, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(a, k, mid)) {
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

    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll k = upper_binary_search(i + 1, n - 1, a, i) - lower_binary_search(i + 1, n - 1, a, i) + 1;

        cout << upper_binary_search(i + 1, n - 1, a, i) << " ";
        cout << lower_binary_search(i + 1, n - 1, a, i) << " ";
        cout << ans << endl;

        if (k != n - i) ans += k; 
    }

    cout << ans << endl;
}