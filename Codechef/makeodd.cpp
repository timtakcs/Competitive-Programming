#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            if (b % 2) odd++;
            else even++;
        }

        if (odd == n) {
            cout << 0 << endl;
        }
        else if (x % 2) {
            if (even % 2) {
                cout << even/2 + 1 << endl;
            } else {
                cout << even / 2 << endl;
            }
        } else {
            if (odd >= even) {
                cout << even << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}