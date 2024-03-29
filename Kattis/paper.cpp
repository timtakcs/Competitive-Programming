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
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int n; cin >> n;
    double tape = 0;
    double add = pow(2, -3.0/ 4);
    ll needed = 2;
    while(n-- > 1) {
        tape += needed / 2 * add;
        ll num;
        cin >> num;
        if(num >= needed) {
            cout << setprecision(10) << fixed << tape;
            return 0;
        }
        needed -= num;
        needed *= 2;
        add /= pow(2,.5);
    }
    cout << "impossible";
    return 0;
}