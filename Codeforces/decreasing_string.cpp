#include <iostream>
#include<bits/stdc++.h>
#include <stack>
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
        string s; cin >> s;
        ll pos; cin >> pos;
        pos--;

        vector<char> st;
        int len = s.length();
        bool ok = pos < len;
        s += '$';
        for (auto c: s) {
            while (!ok && st.size() > 0 && st.back() > c) {
                pos -= len;
                len--;

                st.pop_back();

                if (pos < len) ok = true;
            }

            st.push_back(c);
        }

        cout << st[pos];
    }
}