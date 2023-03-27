#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + a[i];
        }

        for (int i = 0; i < q; i++) {
            int l, r, k; cin >> l >> r >> k;
            l--; r--;

            ll right = prefix[n - 1] - prefix[r];
            ll left = (l == 0) ? 0 : prefix[l - 1];

            ll total = left + right;
            ll sub = k * (1ll * r - 1ll* l + 1ll);

            // cout << sub << "fdafsd" << endl;
            // cout << l << " " << left << " " <<  r << " " <<right << endl;
            // continue;

            if ((total % 2 == 0 && sub % 2 == 1) || (total % 2 == 1 && sub % 2 == 0)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }


    }
}