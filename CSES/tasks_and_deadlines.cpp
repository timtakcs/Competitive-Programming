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

int main() {
    setIO();

    int n; cin >> n;
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        ll t, d; cin >> t >> d;
        a[i] = {t, d};
    }

    sort(a.begin(), a.end());

    ll cur = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[i].s - (a[i].f + cur);
        cur += a[i].f;
    }

    cout << ans << endl;
}