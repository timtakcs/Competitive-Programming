#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<long> m(7);
    long total = 0;
    cin >> m[2] >> m[3] >> m[5] >> m[6];
    while (m[2] && m[5] && m[6]) {
        total += 256;
        m[2]--;m[5]--;m[6]--;
    }
    while (m[2] && m[3]) {
        total += 32;
        m[2]--;m[3]--;
    }

    cout << total << endl;
}