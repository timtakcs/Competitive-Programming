#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    int n;

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

    
}