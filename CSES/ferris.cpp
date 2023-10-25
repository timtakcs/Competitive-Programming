#include <iostream>
#include<bits/stdc++.h>
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

    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;

    int l = 0; int r = n - 1;

    while (l <= r) {
        if (a[l] + a[r] <= x) {
            ans++; l++; r--;
        } else {
            r--;
            ans++;
        }
    }

    cout << ans << endl;
}