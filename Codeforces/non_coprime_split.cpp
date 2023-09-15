#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
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
        int l, r; cin >> l >> r;

        if (r < 4) {
            cout << -1 << endl;
            continue;
        }

        if (l != r) {
            if (r % 2 == 0) cout << r / 2 << " " << r / 2 << endl;
            else cout << (r - 1) / 2 << " " << (r - 1) / 2 << endl;
        } else {
            if (l % 2 == 0 && l != 2) cout << l/2 << " " << l/2 << endl;

            else if (l % 2 == 0 && l == 2) {
                if (r < 4) cout << -1 << endl;
                else cout << ((l + 2) / 2) << " " << ((l + 2) / 2) << endl;
            } else if (l % 2 == 1 && l == 1) cout << -1 << endl;
            else {
                bool found = false;

                for (int i = 2; i <= sqrt(l); ++i) {
                    if (l % i == 0) {
                        int f = l / i;

                        for (int j = 1; j < i; ++j) {
                            int lhs = f * j;
                            int rhs = f * (i - j);

                            if (gcd(lhs, rhs) != 1) {
                                cout << lhs << " " << rhs << endl;
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }
                }

                if (!found) cout << -1 << endl;
            }
        }
    }
}