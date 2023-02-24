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

    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    bool flag = false;

    for (int i = 1; i <= pow(2, n); i++) {
        // cout << i << endl;

        int sum = 0;

        for (int j = 1; j <= n; j++) {
            if (i & (1 << (n - j))) sum += a[j-1];
            else sum -= a[j-1];
        }

        if (sum % 360 == 0) {
            cout << "YES" << endl;
            flag = true;
            break;
        }
    }

    if (!flag) cout << "NO" << endl;
}