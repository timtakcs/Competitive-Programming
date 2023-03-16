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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maxi = max(arr[i], maxi);
        }

        vector<int> freq (maxi + 1, 0);
        vector<int> prefix(maxi + 1);

        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        ll prev = 1;
        ll count = 0;

        for (int i = 1; i <= n; i++) {
            prev = freq[i] * prev;
            prev %= MOD;
            count += prev;
            count %= MOD;
        }

        cout << count << endl;
    }
}