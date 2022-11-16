#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    int n;

    // min heap
    // priority_queue<int> heap;

    // max heap
    // priority_queue<int, vector<int>, greater<int>> heap;

    cin >> n >> q;

    long long x[n];
    long long s[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    s[0] = x[0];
    for (int i = 1; i < n; i++) {
        s[i] = s[i - 1] + x[i];
    } 

    int a;
    int b;

    while (q--) {
        cin >> a;
        cin >> b;
        cout << s[b] - s[a - 1] << endl;
    } 
}