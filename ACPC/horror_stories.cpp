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
        bool ok = false;
        double x, y; cin >> x >> y;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            double x1, y1; cin >> x1 >> y1;

            if (floor(sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1)) - 0.00000001) < 8) {
                if (!ok) {
                    cout << "light a candle" << endl;
                    ok = true;
                }
            }
        }

        if (!ok) cout << "curse the darkness" << endl;
    }
}