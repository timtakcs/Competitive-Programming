#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
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
        ll m, n; cin >> m >> n;

        if (n > m) cout << "NO" << endl;
        else if (n == m) cout << "YES" << endl;
        else {
            while (m % 2 == 0) {
                m /= 2;
            }

            if (n % m == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}