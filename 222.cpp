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

    ll sum = 0;

    for (int k = 10; k < 21; k++) {
        sum += (k * k);
    }

    ll ans = ((20 * 21 * 41 - 9 * 10 * 19) / 6);

    cout << sum << " " << ans << endl;
}