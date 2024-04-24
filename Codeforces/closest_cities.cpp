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

constexpr ll INF = 1e12;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int closest(vector<ll> &a, int i, int n) {
    ll left = (i - 1 >= 0) ? a[i - 1] : INF;
    ll right = (i + 1 < n) ? a[i + 1] : INF;
    ll cur = a[i];

    if (abs(cur - left) < abs(cur - right)) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n); 
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<ll> prefix(n);
        vector<ll> suffix(n);

        prefix[0] = 0;
        suffix[n - 1] = 0;

        for (int i = 1; i < n; i++) {
            int next = closest(a, i - 1, n);
            if (next == 1) {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1] + abs(a[i] - a[i - 1]);
            }
        } 

        for (int i = n - 2; i >= 0; i--) {
            int next = closest(a, i + 1, n);
            if (next == -1) {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1] + abs(a[i] - a[i + 1]);
            }
        }

        int m; cin >> m;
        while (m--) {
            int l, r; cin >> l >> r;

            l--; r--;

            if (l < r) {
                cout << prefix[r] - prefix[l] << endl;
            } else {
                cout << suffix[r] - suffix[l] << endl;
            }
        } 
    }
}