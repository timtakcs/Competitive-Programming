#include <iostream>
#include <map>
#include <set>
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
        vector<set<int>> sets;
        set<int> total;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            
            set<int> s;
            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                s.insert(x);
                total.insert(x);
            }

            sets.push_back(s);
        }

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;

        for (auto number: total) {
            set<int> un;
            for (int i = 0; i < n; i++) {
                if (!sets[i].count(number)) {
                    un.insert(sets[i].begin(), sets[i].end());
                }
            }

            ans = max(ans, (ll)un.size());
            un.clear();
        }

        cout << ans << endl;

    }
}
