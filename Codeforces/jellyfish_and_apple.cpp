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

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        if (n % m == 0) {
            cout << 0 << endl;
        } else {
            if (ceil(log2(m / gcd(n, m))) == floor(log2(m / gcd(n, m)))) {
                int bits = __builtin_popcount(m)
            } else {
                cout << -1 << endl;
            }
        }
    }
}