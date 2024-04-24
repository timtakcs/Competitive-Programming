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

    int l, x; cin >> l >> x;

    int cur = 0;
    int ans = 0;

    for (int i = 0; i < x; i++) {
        string s; cin >> s;
        int p; cin >> p;

        if (s == "enter") {
            if (cur + p > l) {
                ans++;
            } else {
                cur += p;
            }
        } else {
            cur -= p;
        }
    }

    cout << ans << endl;
}