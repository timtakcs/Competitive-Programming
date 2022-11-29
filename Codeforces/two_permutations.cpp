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
        int n, a, b; cin >> n >> a >> b;
        if((a + b <= n - 2) || (a == b == n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}