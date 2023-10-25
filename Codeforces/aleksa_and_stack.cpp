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
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(3);

        for (int i = 2; i < n; i++) {
            int cur = ans[i - 1] + 1;
            while ((3 * cur) % (ans[i - 1] + ans[i - 2]) == 0) cur++;
            ans.push_back(cur);
        }

        for (auto x: ans) {
            cout << x << " ";
        }
        cout << endl;

    }
}