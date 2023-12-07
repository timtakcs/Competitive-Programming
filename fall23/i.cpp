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

int main() {
    setIO();

    int n; cin >> n;
    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        char c; cin >> c;

        int cat = 0;
        
        if (c == 'L') cat = 1;

        a[i] = {x, cat};
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i].s == 1 && a[i + 1].s == 1) {
            ans += a[i + 1].f - max(17, a[i].f);
        } else if (a[i].s == 1 && a[i + 1].s == 0) {
            ans += (a[i + 1].f - a[i].f + 1) / 2;
        } else if (a[i].s == 0 && a[i + 1].s == 1) {
            ans += (a[i + 1].f - a[i].f + 1) / 2 - 1;
        }
    }

    if (a[0].s == 1) {
        ans += max(0, a[0].f - 17);
    }

    if (a[n - 1].s == 1) {
        ans += 1e9 - a[n - 1].f + 1;
    }

    cout << ans << endl;
}