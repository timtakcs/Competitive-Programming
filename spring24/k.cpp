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

void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    setIO();

    int n; cin >> n;
    set<int> s;
    vector<int> d(n + 1);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        auto lb = s.lower_bound(x);
        auto ub = s.upper_bound(x);

        s.insert(x);

        if (s.size() == 1) {
            d[x] = 1;
        } else if (lb == s.end()) {
            d[x] = d[*ub] + 1;
        } else if (ub == s.end()) {
            d[x] = d[*lb] + 1;
        } else {
            d[x] = min(d[*lb], d[*ub]) + 1;
        }

        ans = max(ans, d[x]);
    }

    print_vector(d);

    cout << ans << endl;
}