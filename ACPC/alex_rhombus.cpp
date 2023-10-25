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

ll solve(int n) {
    if (n == 1) return 1;
    else return (4 * (n - 1)) + solve(n - 1);
}

int main() {
    setIO();

    ll n; cin >> n;

    cout << solve(n) << endl;
}