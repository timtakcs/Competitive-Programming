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

    int mx = 0;
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int a; cin >> a;
            sum += a;
        }

        if (sum > mx) {
            mx = sum;
            idx = i;
        }

        sum = 0;
    }

    cout << idx + 1 << " " << mx << endl;
}