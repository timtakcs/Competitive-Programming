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

bool possible(double mid, int l, vector<double>& people, int n) {
    int from = 0;
    int cur = 0;

    while (from <= n) {
        if (cur > people.size() || people[cur] - from > mid) {
            if (cur < people.size()) {
                from = people[cur];
            } else {
                from = n + 1;
            }
        } else {
            from += mid;

            while (cur < people.size() && people[cur] < from) {
                cur++;
            }
        }
    }
    
}

int binary_search(double low, double high, int l, vector<double> &people, int n) {
    if (low == high) {
        return high;
    }

    int mid = ((high - low) / 2) + low;
    if (possible(mid, l, people, n)) {
        return binary_search(low, mid, l, people, n);
    } else {
        return binary_search(mid + 1, high, l, people, n);
    }
}

int main() {
    setIO();

    int n; cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


}