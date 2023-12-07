#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <map>
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

/*
1
11 10
10 5 7 6 9 4 2 8 1 11 3
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
*/

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> left;
        vector<int> right(n);

        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (s.size() && a[s.top()] <= a[i]) {
                right[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        while (s.size()) {
            right[s.top()] = n;
            s.pop();
        }

        for (int i = 0; i < n; i++) {
            while (s.size() && a[s.top()] <= a[i]) {
                s.pop();
            } 

            if (!s.size()) left.push_back(-1); 
            else left.push_back(s.top());

            s.push(i);
        }

        for (int i = 0; i < q; i++) {
            int c, k; cin >> c >> k;

            c--;

            if (left[c] != -1) {
                cout << 0 << endl;
            } else {
                if (a[c] == n) {
                    cout << max(0, k - c + (c != 0)) << endl;
                } else {
                    k -= c - (c != 0);

                    cout << min(k, right[c] - c - 1) << endl;
                }
            }
        }
    }
}