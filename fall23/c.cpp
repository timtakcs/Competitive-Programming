#include <iostream>
#include <bits/stdc++.h>
#include <set>
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

    int n; cin >> n;

    string s; cin >> s;

    int start = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            start = i;
            break;
        }
    }

    set<char> keys;
    bool possible = true;

    int l = start - 1;
    int r = start + 1;

    int last_l = l;
    int last_r = r;

    while (l >= 0 && r <= n - 1 && possible) {
        if (s[r] >= 'a' && s[r] <= 'z') {
            keys.insert(toupper(s[r]));
            r++;
        } else if (s[r] >= 'A' && s[r] <= 'Z') {
            if (keys.find(s[r]) != keys.end()) r++;
        } else {
            r++;
        }

        if (s[l] >= 'a' && s[l] <= 'z') {
            keys.insert(toupper(s[l]));
            l--;
        } else if (s[l] >= 'A' && s[l] <= 'Z') {
            if (keys.find(s[l]) != keys.end()) l--;
        } else {
            l--;
        }

        if (l == last_l && r == last_r) possible = false;
        else {
            last_l = l;
            last_r = r;
        }
    }

    if (l != -1 && r != n && start != 0 && start != n - 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}