#include <iostream>
#include <bits/stdc++.h>
#include <set>
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
        int n, m, k; cin >> n >> m >> k;

        vector<int> a(n);
        vector<int> b(n);

        multiset<int> active;
        multiset<int> comp;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
            comp.insert(b[i]);
            active.insert(b[i]);
        }

        for (int i = 0; i < m; i++) {
            if (active.count(a[i])) {
                auto it = active.find(a[i]);
                active.erase(it);
            }
        }

        for (int r = m; r < n; r++) {
            int left = a[r - m - 1];
            int right = a[r];

            if (comp.count(left) > active.count(left))
        }

    }
}