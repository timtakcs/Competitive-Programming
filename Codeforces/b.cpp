#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
// #define s second
#define mp make_pair
#pragma GCC optimize "trapv"

void solve(vector<int> &nums, int m, int s) {
    int sum = 0;
    int mx = 0;
    for (auto &n : nums) {
        sum += n;
        mx = max(n, mx);
    }
    sum += s;

    int theo = (mx *(mx + 1))/2;

    float n = (-1 + sqrt(1 + 8 * sum))/2;

    int k = n;
    float temp = k - n;
    if (!temp) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int m, s; cin >> m >> s;
        vector<int> nums (m);
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
        }
        solve(nums, m, s);
    }
}
