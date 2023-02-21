#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void build(vector<int> &tree, vector<int> &a, int vertex, int left, int right) {
    if (right == left) {
        tree[vertex] = a[left];
    }
    else {
        int mid = (left + right) / 2;
        build(tree, a, vertex * 2, left, mid);
        build(tree, a, vertex * 2 + 1, mid + 1, right);

        tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
    }
}

int query(vector<int> &tree, int vertex, int vl, int vr, int l, int r) {
    if (l > r) return 0;
    if (l == vl && r == vr) return tree[vertex];
    else {
        int vmid = (vl + vr) / 2;
        return query(tree, vertex * 2, vl, vmid, l, min(vmid, r)) + query(tree, vertex * 2 + 1, vmid + 1, vr, max(vmid + 1, l), r);
    }
}

void insert(vector<int> &tree, int vertex, int pos, int value, int l, int r) {
    if (l == r) tree[vertex] = value;
    else {
        int mid = (l + r) / 2;
        if (pos < mid) {
            insert(tree, pos, vertex, value, l, mid);
        }
        else {
            insert(tree, pos, vertex, value, mid + 1, r);
        }

        tree[vertex] = tree[vertex * 2] + tree[vertex * 2 + 1];
    }
}

int main() {
    setIO();

    int n, q; cin >> n >> q;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tree(n + 1);
    build(tree, a, 1, 1, n);

    while (q--) {
        int k, i1, i2; cin >> k >> i1 >> i2;

        if (k == 1) {
            insert(tree, 1, i1, i2, 1, n);
        }
        else {
            cout << query(tree, 1, 1, n, i1, i2) << endl;
        }
    }
}