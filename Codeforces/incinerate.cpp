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

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        set<pair<int, int>> x;

        for (int i = 0; i < n; i++) {
            x.insert({a[i], b[i]});
        }

        bool wins = false;
        int d = 0;
        while (k > 0) {
            d += k;
            auto lb = x.lower_bound({d, 0});

            if (lb == x.end()) {
                wins = true;
                break;
            } else {
                k -= (*lb).s;
            }

            cout << k << endl;
        }

        if (wins) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}