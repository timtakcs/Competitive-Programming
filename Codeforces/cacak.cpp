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
        ll n, k, x; cin >> n >> k >> x;
        ll z = k * (k + 1) / 2;
        ll y = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        if ((x >= z && x <= y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}