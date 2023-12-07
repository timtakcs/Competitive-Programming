#include <iostream>
#include <bits/stdc++.h>
#include <map>
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
        int n; cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }

        if (m.size() < 2) cout << "Yes" << endl;
        else if (m.size() > 2) cout << "No" << endl;
        else {
            if (abs(next(m.begin())->second - m.begin()->second) > 1) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}