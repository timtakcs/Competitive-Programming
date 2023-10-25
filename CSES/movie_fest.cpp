#include <iostream>
#include<bits/stdc++.h>
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
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        t[i] = {e, s};
    }

    sort(t.begin(), t.end());

    int c = t[0].f;
    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (t[i].s >= c) {
            ans++;
            c = t[i].f;
        }
    }

    cout << ans << endl;
}