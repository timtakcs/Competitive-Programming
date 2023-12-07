#include <iostream>
#include <bits/stdc++.h>
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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> sum_b(n);
        vector<int> sum_a(n);

        if (s[n - 1] == 'B') sum_b[n - 1] = 1;
        else sum_b[n - 1] = 0;

        if (s[0] == 'A') sum_a[0] = 1;
        else sum_a[0] = 0;

        for (int i = n - 2; i >= 0; i--) {
            sum_b[i] = sum_b[i + 1] + (s[i] == 'B');
        }    

        for (int i = 1; i < n; i++) {
            sum_a[i] = sum_a[i - 1] + (s[i] == 'A');
        }

        if (sum_b[0] == k) {
            cout << 0 << endl;
        } else if (sum_b[0] < k) {
            int idx = 0;

            while (sum_a[idx] != k - sum_b[0]) {
                idx++;
            }

            cout << 1 << endl;
            cout << idx + 1 << " B" << endl;
        } else {
            int idx = 0;

            while (sum_b[idx] != k + 1) {
                idx++;
            }
            cout << 1 << endl;
            cout << idx + 1 << " A" << endl;
        }
    }
}