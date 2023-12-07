#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int l, d, x; cin >> l >> d >> x;

    int total = l + d;
    int ans = 0;

    while ((((double)(l) / (double)(total)) * 100.0) < (double)x) {
        l++;
        total++;
        ans++;
    }

    cout << ans << endl;
}