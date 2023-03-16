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

void dfs(vector<vector<int>> &tree, int u, int p, int depth, int &x, int &d){
    for (auto child: tree[u]){
        if (child != p){
            dfs(tree, child, u, depth + 1, x, d);
        }
    }
    if (depth > d) d = depth, x = u;
}

int main() {
    setIO();

    int n; cin >> n;

    vector<vector<int>> tree(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    int x = 0, d = 0;

    dfs(tree, 0, 0, 0, x, d);
    dfs(tree, x, 0, 0, x, d);

    cout << d << endl;
}
