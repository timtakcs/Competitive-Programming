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
        set<int> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        bool found = false;
        
        int l = 0;
        int r = n - 1;

        int mn; int mx;

        while (l < r) {
            mx = *s.rbegin();
            mn = *s.begin();

            if (a[l] == mx || a[l] == mn) {
                s.erase(a[l]);
                l++;
            } else if (a[r] == mx || a[r] == mn) {
                s.erase(a[r]);
                r--;
            } else {
                found = true;
                cout << l + 1 << " " << r + 1 << endl;
                break;
            }
        }

        if (!found) cout << -1 << endl;
        
    }
}