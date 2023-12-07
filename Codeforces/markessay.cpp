#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<long long, long long>

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
        int n, c, q; cin >> n >> c >> q;

        string s; cin >> s;
        vector<pii> ops(c);

        ll start_len = n;

        for (int i = 0; i < c; i++) {
            ll a, b; cin >> a >> b;
            ops[c - i - 1] = {a, b};
            start_len += b - a + 1;
        }

        for (int i = 0; i < q; i++) {
            ll k; cin >> k;
            ll cur_len = start_len;
            int op = 0;
            while (k > n) {
                cur_len -= ops[op].s - ops[op].f + 1;
                if (cur_len < k) {
                    k = ops[op].f + (k - cur_len - 1);
                }
                op++;
            }

            cout << s[k - 1] << endl;
        }
    }
}