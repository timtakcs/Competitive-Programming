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

    int n, l, r, x; cin >> n >> l >> r >> x;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int count = 0;

    for (int i = 1; i <= pow(2, n); i++) {
        int maxi = -INF;
        int mini = INF;
        int sum = 0;

        for (int j = 1; j <= n; j++) {
            if (i & (1<<(n - j))) {
                int p = c[j - 1];

                sum += p;
                mini = min(mini, p);
                maxi = max(maxi, p);
            }
        }

        if (sum >= l && sum <= r && (maxi - mini >= x)) {
            count++;
        }
    }

    cout << count << endl;
}