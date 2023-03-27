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
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int n, m; cin >> n >> m;
    vector<int> t(n, 0);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int p, x; cin >> p >> x;
        p--;
        t[p] += x;
        ans += t[p];
        cout << ans << endl;
    }
}