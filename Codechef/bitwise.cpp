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
        unsigned int a = 0;
        unsigned int b = INT32_MAX;
        unsigned int c = 0;
        unsigned int d = 0;

        ll n; cin >> n;

        for (int i = 0; i < 32; i++) {
            if ((1 << i) & n) a |= (1 << i);
        }

        cout << a << " " << b << " " << c << " " << d << " " << endl;
        cout << (((a & b) | c) ^ d) << endl;
    }
}