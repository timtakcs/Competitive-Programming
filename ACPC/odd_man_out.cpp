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
    for (int x = 1; x <= t; x++) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        set<int> lonely;
        for (int i = 0; i < n; i++) {
            if (lonely.find(a[i]) != lonely.end()) {
                lonely.erase(a[i]);
            } else {
                lonely.insert(a[i]);
            }
        }

        cout << "Case #" << x << ": ";

        for (auto num: lonely) {
            cout << num << " ";
        }
        cout << endl;
    }
}