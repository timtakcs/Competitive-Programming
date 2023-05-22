#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> cnt;

        for (int i = 0; i < s.length(); i++) {
            if (cnt.count(s[i])) cnt[s[i]]++;
            else cnt[s[i]] = 1;
        } 

        int odd = 0; 
        int even = 0;

        for (auto c: cnt) {
            if (c.second % 2 == 0) even++;
            else odd++;
        }

        if (odd == 1 && even == 0) {
            if (n > 2) cout << 2 << endl;
            else cout << 0 << endl;
        } else if (even >= 1 && odd == 0) {
            cout << 1 << endl;
        } else if (odd > 1 && even >= 0) {
            cout << 0 << endl;
        } else if (odd == 1 && even > 0) {
            cout << 1 << endl;
        }
    }
}