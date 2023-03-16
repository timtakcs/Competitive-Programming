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

void calc(vector<vector<int>> &tree, int p, int v, vector<vector<int>> &memo, int l) {
    memo[v][0] = p;
    for (int i = 1; i <= l; i++) {
        memo[v][i] = memo[memo[v][i-1]][i-1];
        if (memo[v][i] == -1) break;
    }
}

int query(vector<vector<int>> &memo, int v, int k, int l) {
    for (int i = 0; i < l + 1; i++) {
        if (k & (1 << i)) {
            v = memo[v][i];
            if (v == -1) break;
        }
    }

    return v;
}

int main() {
    setIO();

    int n, q; cin >> n >> q;
    int l = (int)ceil(log2(n));
    vector<vector<int>> tree(n);
    vector<vector<int>> memo(n, vector<int>(l + 1, -1));

    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        tree[x-1].push_back(i);
    }
    
    for (int p = 0; p < n; p++) {
        for (auto u: tree[p]) {
            calc(tree, p, u, memo, l);
        }
    }

    for (int j = 0; j < q; j++) {
        int a, k; cin >> a >> k;

        int val = query(memo, a-1, k, l);

        cout << ((val == -1) ? val : val + 1) << endl;
        // cout << val << endl;
    }
}