#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << a[0] << endl;
            continue;
        };

        vector<ll> even;
        vector<ll> odd;

        ll max_val = -1e9;

        for (int i = 0; i < n; i++) {
            if (i % 2) odd.push_back(a[i]);
            else even.push_back(a[i]);
            max_val = max(max_val, a[i]);
        }

        ll even_sum = 0;
        ll odd_sum = 0;

        for (int i = 0; i < even.size(); i++) {
            even_sum += max(even[i], 0ll);
        }

        for (int i = 0; i < odd.size(); i++) {
            odd_sum += max(odd[i], 0ll);
        }

        if (max_val < 0) cout << max_val << endl;
        else cout << max(even_sum, odd_sum) << endl;
    }
}