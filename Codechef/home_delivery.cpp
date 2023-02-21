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

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    link[b] = a;
}

int main() {
    setIO();

    int t; cin >> t;

    while(t--) {
        int n, m; cin >> n >> m;
        
        vector<int> link(n);

        for(int i = 0; i < n; i++) {
            link[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            unite(a, b, link);
        }

        int q; cin >> q;

        while(q--) {
            int c, d; cin >> c >> d;
            if (find(c, link) == find(d, link)) cout << "YO" << endl;
            else cout << "NO" << endl;
        }
    }
}