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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        reverse(s.begin(), s.end());

        int l = 0;
        int r = 0;

        ll cnt = 0;
        ll ans = 0;

        while (l < n && s[l] != '1') l++;

        r = l;

        while (r < n - 1 && s[r] != '0') {
            if (s[r] == '1') cnt++;
            r++;
        }

        for (int i = 0; i < n; i++) {
            if (i < l) {
                cout << ans << " ";
                continue;
            }

            if (s[r] == '1') {
                cout << -1 << " ";
                continue;
            }
            
            ans += cnt;
            cout << ans << " ";
            
            l++;
            s[r] = '1';
            while (r < n - 1 && s[r] != '0') {
                r++;
                if (s[r] == '1') cnt++;
            }
        }

        cout << endl;
    }
}