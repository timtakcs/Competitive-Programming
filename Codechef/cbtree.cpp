#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<pair<int, int>>> tree(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v, w; cin >> u >> v >> w;
            tree[u].push_back(mp(v, w));
            tree[v].push_back(mp(u, w));
        }

        
    }
}