#include <iostream>
#include <iomanip>
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> sums(n, 0);

        for (int i = 0; i < n; i++) {
            int w; cin >> w;
            for (int j = 0; j < w; j++) {
                ll x; cin >> x;
                sums[i] += x;
            }
        }

        sort(sums.begin(), sums.end());
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i] + sums[i - 1];
        }

        long double ans = 0;

        for (int i = 0; i < n; i++) {
            ans += sums[i];
        }

        ans /= sums.size();

        cout << fixed << setprecision(10) << ans << endl;

    }
}