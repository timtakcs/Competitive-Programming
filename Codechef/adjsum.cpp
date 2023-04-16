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
        int n; cin >> n;

        int max_count = 0;

        vector<int> a(n);
        map<int, int> count;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (count.count(a[i])) count[a[i]]++;
            else count[a[i]] = 1;
        }

        sort(a.begin(), a.end());

        int last = a.back();
        a.pop_back();
        int second_last = a.back();

        if (last == second_last) {
            max_count = count[last];
        } else {
            max_count = count[last] + count[second_last];
        }

        if (ceil((double)n / 2.0) >= max_count && n > 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}