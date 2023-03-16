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
    // int t = 1;
    while(t--) {
        ll n; cin >> n;
        int outer = n / 2;
        ll total = 0;

        for (ll i = 1; i <= outer; i++) {
            total += i * i;
        }

        cout << total * 8 << endl;
    }


}