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

void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        int cnt = __builtin_popcount(k);

        vector<int> bits;

        if (n == 1) {
            cout << k << endl;
        } else {
            int msb = log2(k);
            int all_bits = 0;

            for (int i = 0; i < msb; i++) {
                all_bits |= (1 << i);
            }

            int rem = k - all_bits;

            bits.push_back(all_bits);
            bits.push_back(rem);

            while (bits.size() < n) {
                bits.push_back(0);
            }

            print_vector(bits);
        }

    }
}