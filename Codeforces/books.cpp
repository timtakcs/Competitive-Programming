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

    int n, t; cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int r = 0;

    int sum = 0;
    int max_dif = 0;

    // taken from editorial because my old two pointer approach could get out of bounds when s == n - 1

    for (int i = 0; i < n; i++) {
        while (r < n && sum + a[r] <= t) {
            sum += a[r];
            r++;
        }

        max_dif = max(max_dif, r - i);
        sum -= a[i];
    }

    cout << max_dif << endl;
}