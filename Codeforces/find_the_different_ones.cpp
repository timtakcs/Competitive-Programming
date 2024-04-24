#include <iostream>
#include <bits/stdc++.h>
#include <stack>
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

void next_dif(vector<int> &a, vector<int> &out, int n) {
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] != a[i]) {
            out[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); 
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> next(n, -1);
        next_dif(a, next, n);

        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            l--; r--;

            if (next[l] == -1 || next[l] > r) cout << -1 << " " << -1 << endl;
            else cout << l + 1 << " " << next[l] + 1 << endl;
        }

    }
}