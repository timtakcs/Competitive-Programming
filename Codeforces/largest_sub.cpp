#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

// resolve

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

bool is_sorted(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i - 1]) return false;
    }
    return true;
}

int binary_search(ll l, ll h, string s, char c) {
    int ans = 0;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (c > s[mid]) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

string lex_max(string s) {
    string ans = "";
    ans += s[0];

    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= ans.back()) ans += s[i];
        else {
            int pos = binary_search(0, ans.size(), ans, s[i]);
            ans = ans.substr(0, pos);
            ans += s[i];
        }
    }

    return ans;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        if (is_sorted(s)) cout << 0 << endl;
        else {
            string x = lex_max(s);
            if (x.size() == 1) cout << -1 << endl;
            else cout << x.size() - 1 << endl;
        }
    }
}