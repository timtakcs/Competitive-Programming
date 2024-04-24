#include <iostream>
#include <bits/stdc++.h>
#define ll long long
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

int diff(string &s1, string &s2) {
    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) ans++;
    }
    return ans;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int half = n / 2;

        string first = s.substr(0, half);
        string second = s.substr(n - half, n);
        reverse(second.begin(), second.end());

        int dif = diff(first, second);
        int free = n % 2;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (i - dif >= 0 && i <= n - dif && ((i - dif) % 2 == 0 || free)) {
                ans += '1';
            } else {
                ans += '0';
            }
        }

        if (first == second) {
            ans += '1';
        } else {
            ans += '0';
        }

        cout << ans << endl;
    }
}