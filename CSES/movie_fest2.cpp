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
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int n, k; cin >> n >> k;

    vector<pair<int, int>> m(n);

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        m[i] = {b, a};
    }

    sort(m.begin(), m.end());

    multiset<int, greater<int>> x;
    for (int i = 0; i < k; i++) x.insert(0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto ub = x.lower_bound(m[i].s);

        if (ub != x.end()) {
            x.erase(ub);
            x.insert(m[i].f);
            ans++;
        }
    }

    cout << ans << endl;
}