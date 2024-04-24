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

int get_wins(vector<int> &a, int n, int k) {
    int ans = 0;

    if (k != 0 && a[k - 1] < a[k]) ans++;
    for (int i = k + 1; i < n; i++) {
        if (a[i] < a[k]) ans++;
    } 

    return ans;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        k--;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] > a[k]) {
                swap(a[i], a[k]);
                ans = max(ans, get_wins(a, n, i));
                swap(a[i], a[k]);
                break;
            }
        }

        if (k != 0) {
            swap(a[0], a[k]);
            ans = max(ans, get_wins(a, n, 0));
        }

        cout << ans << endl;
        
    }
}