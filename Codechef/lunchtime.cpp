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
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                for (int l = i -  1; l >= 0; l--) {
                    if (a[l] > a[i]) break;
                    if (a[l] == a[i]) dp[i]++;
                }
            }
            if (i != n - 1) {
                for (int r = i + 1; r < n; r++) {
                    if (a[r] > a[i]) break;
                    if (a[r] == a[i]) dp[i]++;
                }
            }
        }

        for (auto a: dp) {
            cout << a <<" ";
        }
        cout << endl;
    }
}