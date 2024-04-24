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

void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
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

        vector<int> f;
        vector<int> s;

        int cur = a[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] == cur) {
                cnt++;
            } else {
                f.push_back(cnt);
                s.push_back(cur);

                cur = a[i];
                cnt = 1;
            }
        }

        f.push_back(cnt);
        s.push_back(cur);

        if (s.size() == 1) cout << -1 << endl;
        else {
            int ans = INF;
            for (int i = 0; i < s.size(); i += 2) {
                ans = min(ans, f[i]);
            }
            cout << ans << endl;
        }

    }
}