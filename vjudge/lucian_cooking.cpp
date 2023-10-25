#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int n; cin >> n;
    long double x, y; cin >> x >> y;

    vector<long double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;

    long double ratio = y / x;

    for (int i = 0; i < n; i++) {
        ans.push_back(floor(a[i] * ratio + 0.000000001));
    }

    for (auto x: ans) {
        cout << x << endl;
    }

}