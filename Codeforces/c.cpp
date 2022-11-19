#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

int main() {
    int t; cin >> t;
    while (t--) {
        int l, r, x; cin >> l >> r >> x;
        int a, b; cin >> a >> b;

        if (a == b) {
            cout << "YES" << endl;
            continue;
        }

        if (abs(r - l) < x) {
            cout << "NO" << endl;
            continue;
        }

        

    }
}