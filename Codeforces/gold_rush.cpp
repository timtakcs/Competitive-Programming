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

bool helper(int n, int m) {
    if (n == m) return true;
    if (n%3 != 0 || m > n) return false;
    else {
        int b = n / 3;
        int a = b * 2;

        return (helper(a, m) || helper(b, m));
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        
        bool valid = helper(n, m);
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}