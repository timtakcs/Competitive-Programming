#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; int h; int v;
    cin >> n >> h >> v;
    cout << max(h, n - h) * max(v, n - v) * 4 << endl;
}