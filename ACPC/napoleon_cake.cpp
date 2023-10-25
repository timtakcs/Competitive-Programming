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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            j = min(i - a[i], j);

            if (i > j) ans.push_back(1);
            else ans.push_back(0);
        }

        for (int i = n - 1; i >= 0; i--) cout << ans[i] << " ";
        cout << endl;
    }
}