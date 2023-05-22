#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

        int even = 0;
        int min_odd = INF;
        int min_even = INF;

        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even++;
                min_even = min(min_even, a[i]);
            }
            else {
                min_odd = min(min_odd, a[i]);
            }
        }

        if (even == n) cout << "YES" << endl;
        else if (min_odd < min_even) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}