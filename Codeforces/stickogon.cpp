#include <iostream>
#include <bits/stdc++.h>
#include <map>
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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }

        int ans = 0;

        for (const auto &pair: cnt) {
            if (pair.second >= 3) {
                ans += pair.second / 3;
            }
        }

        cout << ans << endl;
    }

}