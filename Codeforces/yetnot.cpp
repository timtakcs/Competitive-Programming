#include <iostream>
#include <bits/stdc++.h>
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
        int n = s.length();

        stack<int> big;
        stack<int> small;

        vector<char> ans(n, '-');

        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                if (!small.empty()) {
                    int idx = small.top(); small.pop();
                    ans[idx] = '-';
                }
            } else if (s[i] == 'B') {
                if (!big.empty()) {
                    int idx = big.top(); big.pop();
                    ans[idx] = '-';
                }
            } else if (s[i] <= 'z' && s[i] >= 'a') {
                small.push(i);
                ans[i] = s[i];
            } else if (s[i] <= 'Z' && s[i] >= 'A') {
                big.push(i);
                ans[i] = s[i];
            }
        }

        string a = "";

        for (int i = 0; i < n; i++) {
            if (ans[i] == '-') continue;
            else {
                a += ans[i];
            }
        }
        cout << a << endl;
    }
}