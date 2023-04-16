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
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void build(vector<int> &a, vector<int> &t, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, t, v*2, tl, tm);
        build(a, t, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int maxq(vector<int> &t, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(maxq(t, v*2, tl, tm, l, min(r, tm)), maxq(t, v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        vector<int> t(4e6);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        build(a, t, 1, 1, n);

        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            cout << maxq(t, 1, 0, n, l, r) << endl;
        }
    }
}