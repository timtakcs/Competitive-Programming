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
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> dp(n);
        dp[0] = a[0];

        for (int i = 1; i < n; i++) {
            if(dp[i-1] - 2*a[i-1] - a[i] >  dp[i-1] + a[i]) {
                dp[i] = dp[i-1] - 2*a[i-1] - a[i];
                a[i - 1] = -a[i - 1];
                a[i] = -a[i];
            } else {
                dp[i] = dp[i - 1] + a[i];
            }
        }

        cout << dp[n - 1] << endl;;
    } 
}