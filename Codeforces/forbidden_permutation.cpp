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
        int n, m, d; cin >> n >> m >> d;

        map<int, int> pos;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            pos[p[i]] = i + 1;
        }

        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        int ans = INF;

        for (int i = 0; i < m - 1; i++) {
            if(pos[a[i + 1]] < pos[a[i]] || pos[a[i + 1]] - pos[a[i]] > d) {
                ans = 0;
                break;
            }

            int dist = pos[a[i + 1]] - pos[a[i]];
            
            ans = min(ans, dist);

            int possible = (pos[a[i]] - 1) + (n - pos[a[i + 1]]);

            if (possible >= d - dist + 1) {
                ans = min(ans, d - dist + 1);
            }

        }

        cout << ans << endl;
    }
    
}