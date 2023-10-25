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
    while(t--) {
        int n; cin >> n;

        int x = 1; int y = 2; int z = n - 3;

        if (z % 3 == 0) {
            z -= 2;
            y += 2;
        }

        if (z <= 1 || z == y) cout << "NO" << endl;
        else cout << "YES\n" << x << " " << y << " " << z << endl;
    }
}