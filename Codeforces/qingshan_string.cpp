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

bool is_good(string x) {
    for (int i = 1; i < x.size(); i++) {
        if (x[i] == x[i - 1]) return false;
    }
    return true;
}
/*
1
4 1
0101101101
01010
*/


int main() {
    setIO();

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        string s; cin >> s;
        string t; cin >> t;

        if (is_good(s)) cout << "Yes" << endl;
        else {
            if (!is_good(t)) cout << "No" << endl;
            else {
                if (t.size() % 2 == 0) cout << "No" << endl;
                else {
                    set<char> x;

                    for (int i = 1; i < n; i++) {
                        if (s[i] == s[i - 1]) {
                            x.insert(s[i - 1]);
                        }
                    }

                    if (x.size() == 2) cout << "No" << endl;
                    else {
                        if (t[0] != *x.begin()) cout << "Yes" << endl;
                        else cout << "No" << endl;
                    }
                }
            }
        }
    }
}