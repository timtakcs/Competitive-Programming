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
        int n; cin >> n;
        string s; cin >> s;

        string x;
        x = "1";
        int count1 = 1;

        for (int i = 1; i < n; i++) {
            if ((s[i - 1] - '0') ^ (x[i - 1] - '0')) {
                x += '1';
                count1++;
            } else {
                x += '0';
            }
        }

        x = "0";
        int count0 = 0;

        for (int i = 1; i < n; i++) {
            if ((s[i - 1] - '0') ^ (x[i - 1] - '0')) {
                x += '1';
                count0++;
            } else {
                x += '0';
            }
        }

        cout << max(count1, count0) << endl;

    }
}
