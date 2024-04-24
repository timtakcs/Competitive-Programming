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

void print(vector<pii> &arr) {
    for (auto pair: arr) {
        cout << "[" << pair.first << ", " << pair.second << "]" << endl;
    }
}

int main() {
    setIO();

    // the cakes need to map to the chocolates one to one, because otherwise either a cake or a chocolate gets
    // left alone

    int t; cin >> t;
    while (t--) {
        int n, w, h; cin >> n >> w >> h;
        vector<pii> a(n);
        vector<pii> b(n);

        for (int i = 0; i < n; i++) {
            int pos; cin >> pos;
            a[i] = {pos - w, pos + w};
        }

        for (int i = 0; i < n; i++) {
            int pos; cin >> pos;
            b[i] = {pos - h, pos + h};
        }

        vector<pii> range;
        for (int i = 0; i < n; i++) {
            int left = a[i].f - b[i].f;
            int right = a[i].s - b[i].s;
            range.push_back({left, right});
        }

        int lb = -INF;
        int ub = INF;
    
        for (int i = 0; i < n; i++) {
            lb = max(lb, range[i].f);
            ub = min(ub, range[i].s);
        }

        if (lb <= ub) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}