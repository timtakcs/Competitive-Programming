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
    while(t--) {
        int n, c; cin >> n >> c;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = mp(x, i + 1);
        }

        sort(a.begin(), a.end());

        int count = 0;

        c -= (a[0].f + a[0].s);
        if (c >= 0) {
            count++;
            for (int i = 1; i < n; i++) {
                c -= a[i].f;
                c -= min(a[i].s, n + 1 - a[i].s);
                if (c < 0) break;
                count++;
            }
            cout << count << endl;
        } else cout << 0 << endl;
    }
}