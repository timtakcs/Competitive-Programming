#include <iostream>
#include <bits/stdc++.h>
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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> x;

        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) x.push_back(i);
        }

        if (k == 1 && x.size() != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}