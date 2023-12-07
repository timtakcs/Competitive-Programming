#include <iostream>
#include <bits/stdc++.h>
#include <map>
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

    int n; cin >> n;
    map<int, int> cnt;
    set<int> s;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;

        char c; cin >> c;

        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            s.insert(x);
            cnt[x]++;
        }
    }

    bool possible = false;

    for (auto elem: s) {
        if (cnt[elem] == n) {
            possible = true;
            break;
        }
    }

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}