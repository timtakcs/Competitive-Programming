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
        string s; cin >> s;
        ll pos; cin >> pos;
        ll n = 0;

        int cur = 0;
        int i = s.size();
        while (i > 0) {
            cur += i;
            if (cur >= pos) {
                pos = i - (cur - pos) - 1; 
                n = i;
                break;
            }
            i--;
        }

        vector<pair<char, int>> a;

        for (int i = 0; i < s.size(); i++) {
            a.push_back({s[i], i});
        }

        sort(a.begin(), a.end());

        vector<pair<int, char>> new_a;
        for (int i = 0; i < n; i++) {
            new_a.push_back({a[i].s, a[i].f});
        }

        sort(new_a.begin(), new_a.end());

        cout << new_a[pos].s;
    }
}