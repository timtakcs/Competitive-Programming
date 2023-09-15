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
        int s, d; cin >> s >> d;

        if (d > s || s < 0) cout << "impossible" << endl;
        else {
            float y = (s - d) / 2;

            if ((int)y == y && y >= 0 && (y + y + d == s)) cout << y + d << " " << y << endl;
            else cout << "impossible" << endl;
        }
    }
}

