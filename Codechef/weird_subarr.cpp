#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

int main() {
    setIO();

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> dp(n);

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        else {
            vector<int> arr(n);
            for (int i = 0; i < n;i++) {
                cin >> arr[i];
            }

            dp[0] = 1;
            dp[1] = 3;

            int l = 2;

            for (int i = 2; i < n; i++) {
                if (arr[i] > arr[i - 1]) {
                    l++;
                } else {
                    l = 2;
                }
                dp[i] = dp[i - 1] + l;
            }
        }

        cout << dp[n - 1] << endl;
    }
}