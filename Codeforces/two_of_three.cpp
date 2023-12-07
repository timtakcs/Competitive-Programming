#include <iostream>
#include <bits/stdc++.h>
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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        map<int, vector<int>> cnt;
        vector<int> a(n);

        int k = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]].push_back(i);
        }

        for (const auto& pair : cnt) {
            if (pair.s.size() > 1) k++;
        }

        if (k < 2) cout << "-1" << endl;
        else {
            vector<int> b(n);
            int second = 0;

            for (const auto& pair : cnt) {
                if (pair.s.size() > 1) {
                    b[pair.s[0]] = 1;
                    b[pair.s[1]] = 2 + second;

                    second = !second;
                }
            }

            for (int i = 0; i < n; i++) {
                if (b[i] == 0) b[i] = 1;
            }

            for (auto x: b) cout << x << " ";
            cout << endl;
        }
    }
}