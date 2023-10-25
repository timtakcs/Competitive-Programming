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

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n); vector<int> b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end()); sort(b.begin(), b.end());

    int l = 0; int r = 0;
    int c = 0;

    while (l < n && r < m) {
        if (abs(b[r] - a[l]) <= k) {
            c++; r++; l++;
        } else {
            if (b[r] - a[l] < 0) r++;
            else l++;
        }
    }

    for (int i = l; i < n; i++) {
        if (abs(b[r] - a[i]) <= k) c++;
    }

    cout << c << endl;
}