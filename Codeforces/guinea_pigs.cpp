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
        
        int unknown = 0;
        int known = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            if (b == 1) unknown++;
            else {
                known += unknown;
                unknown = 0;
            }

            ans = max(ans, unknown + (known ? known / 2 + 1 : 0));
        }

        cout << ans << endl;
    }
}