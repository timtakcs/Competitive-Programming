#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <map>
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

    int n; cin >> n;
    string s; cin >> s;

    set<char> x;
    map<char, int> m;

    for (int i = 0; i < n; i++) {
        x.insert(s[i]);
    }

    int ans = INF;
    int l = 0;
    for (int r = 0; r < n; r++) {
        m[s[r]]++;
        while (l < r && m[s[l]] > 1) {
            m[s[l]]--;
            l++;
        }

        if (m.size() == x.size()) ans = min(ans, r - l + 1);
    }

    cout << ans << endl;
}