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
    while(t--) {
        int n; cin >> n;
        map<int, int> occ;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (!occ.count(x)) occ[x] = 1;
            else occ[x]++;
            maxi = max(maxi, occ[x]);
        }

        cout << n - maxi << endl;
    }
}