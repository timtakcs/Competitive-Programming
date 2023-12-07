#include <iostream>
#include <bits/stdc++.h>
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

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    if (size[a] > size[b]) {
        swap(a, b);
    } 
    link[b] = a;
    size[a] += size[b];                       
}

int get_closest_element(int x, set<pii> &s) {
    
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int base = abs(a[0] - b[0]) + abs(a[n - 1] + b[n - 1]);

        int ans = 0;

        vector<int> link(2 * n);
        vector<int> size(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            link[i] = i;
        }

        // a is 0 to n - 1, b is n to 2n - 1

        set<pii> a_set;
        set<pii> b_set;

        for (int i = 0; i < n; i++) {
            a_set.insert({a[i], i});
            b_set.insert({b[i], n + i});
        }

        for (int i = 0; i < n; i++) {
            
        }
    }
}