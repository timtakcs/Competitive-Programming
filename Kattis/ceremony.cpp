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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int n; cin >> n;
    vector<int> a(n);
    for (int i =0 ; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = n;

    for (int i = 0; i < n; i++) {
        int cur = n - i - 1;
        cur += a[i];
        ans = min(ans, cur);
    }

    cout << ans << endl;
}