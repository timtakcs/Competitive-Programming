#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
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

bool possible(int mid, vector<int> &wag, int l, int n) {
    int used = 0;
    int from = 1;
    int cur = 0;

    while (from <= n) {
        used++;
        if (cur >= wag.size() || wag[cur] - from > mid) {
            if (cur < wag.size()) {
                from = wag[cur];
            } else {
                from = n + 1;
            }
        } else {
            from += mid;

            while (cur < wag.size() && wag[cur] < from) {
                cur++;
            }
        }
    }

    bool possible = used <= l;
    return possible;
}

int binary_search(int low, int high, vector<int> &wag, int l, int n) {
    if (low == high) {
        return high;
    }

    int mid = ((high - low) / 2) + low;
    if (possible(mid, wag, l, n)) {
        return binary_search(low, mid, wag, l, n);
    } else {
        return binary_search(mid + 1, high, wag, l, n);
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, w, l; cin >> n >> w >> l;

        vector<int> wag(w);
        for (int i = 0; i < w; i++) {
            cin >> wag[i];
        }

        if (l == 1) cout << n << endl;
        else {
            int low = 1;
            int high = n;
            cout << binary_search(low, high, wag, l, n) << endl;
        }
    }
}