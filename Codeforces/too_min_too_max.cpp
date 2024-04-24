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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> difs;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                difs.push_back(abs(a[i] - a[j]));
            }
        }   

        sort(difs.begin(), difs.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 4; i++) {
            ans += difs[i];
        }

        cout << ans << endl;
    }
}