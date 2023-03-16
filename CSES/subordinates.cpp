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

void traverse(vector<vector<int>> &tree, int node, vector<int> &subs) {
    if (tree[node].empty()) subs[node] = 1;
    int sum = 1;
    for (auto c: tree[node]) {
        traverse(tree, c, subs);
        sum += subs[c];
    }
    subs[node] = sum;
}

int main() {
    setIO();

    int n; cin >> n;
    vector<vector<int>> tree(n);
    vector<int> subs(n, 0);
    for (int i = 1; i < n; i++) {
        int c; cin >> c;
        tree[c-1].push_back(i);
    }

    traverse(tree, 0, subs);

    for (auto s: subs) {
        cout << s-1 << " ";
    }
}