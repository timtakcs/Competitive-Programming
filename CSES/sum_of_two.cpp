#include <iostream>
#include<bits/stdc++.h>
#include <map>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i + 1};
    }  
    sort(a.begin(), a.end());
    int l = 0; int r = n - 1;

    while (l < r) {
        if (a[l].f + a[r].f < x) l++;
        else if (a[l].f + a[r].f > x) r--;
        else {
            cout << min(a[l].s, a[r].s) << " " << max(a[l].s, a[r].s) << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

}