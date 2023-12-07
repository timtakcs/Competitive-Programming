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

    int n, sum; cin >> n >> sum;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }

    bool found = false;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (found) break;

        int temp = sum - a[i].f;

        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (l == i) {
                l++; continue;
            } else if (r == i) {
                r--; continue;
            }

            if (a[l].f + a[r].f > temp) {
                r--;
            } else if (a[l].f + a[r].f < temp) {
                l++;
            } else {
                found = true;
                cout << a[i].s << " " << a[l].s << " " << a[r].s << endl;
                break;
            }
        }
    }

    if (!found) cout << "IMPOSSIBLE" << endl;
}