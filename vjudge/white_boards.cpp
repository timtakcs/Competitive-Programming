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
        int n, m; cin >> n >> m;

        vector<ll> a(n);
        vector<ll> b(m);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < m; i++) {
            int min_idx = 0;
            int min_val = INF;
            for (int j = 0; j < n; j++) {
                if (a[j] < min_val) {
                    min_idx = j;
                    min_val = a[j];
                }
            }

            a[min_idx] = b[i];
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }

        cout << sum << endl;
    }
}