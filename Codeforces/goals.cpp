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
        ll sum = 0;
        for (int i = 0; i < n - 1; i++) {
            ll x; cin >> x;
            sum += x;
        }
        
        cout << -1 * sum << endl;
    }
}