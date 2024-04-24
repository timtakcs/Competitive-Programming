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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        bool ans = false;

        if (a[0] == a[1]) {
            for (int i = 2; i < n; i++) {
                if (a[i] % a[0] != 0) {
                    ans = true;
                    break;
                }
            }
        } else {
            ans = true;
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}