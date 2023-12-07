#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <deque>
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
        int n; cin >> n;
        string s; cin >> s;

        map<char, int> freq;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
            mx = max(mx, freq[s[i]]);
        }

        if (mx > n / 2) {
            cout << 2 * mx - n << endl;
        } else {
            cout << n % 2 << endl;
        }

                                        
    }
}