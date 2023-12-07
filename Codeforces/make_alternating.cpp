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

ll factorial(ll n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;

        vector<string> a;

        string cur = "";
        cur += s[0];

        for (int i = 1; i < s.length(); i++) {
            if (s[i] != cur.back()) {
                a.push_back(cur);
                cur = "";
            }
            cur += s[i];
        }

        a.push_back(cur);

        ll ops = 0;
        ll ways = 1;

        ll c = factorial((ll)s.size() - a.size());

        for (auto x: a) {
            ops += x.length() - 1;
            ways *= x.length() * c;
        }

        cout << ops << " " << ways << endl;
    }
}