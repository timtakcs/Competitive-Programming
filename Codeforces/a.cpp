#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

void solve (string x) {
    string yes = "Yes";

    bool flag = false;
    int index = 0;
    for (int i = 0; i < 3; i++) {
        if (yes[i] == x[0]) {
            index = i;
            flag = true;
        }
    }

    if(!flag) {
        cout << "NO" << endl;
        return;
    }

    flag = true;

    for (int i = 0; i < x.size(); i++) {
        if (index > 2) index = 0;
        if (x[i] != yes[index]) {
            flag = false;
            break;
        }
        index++;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        string x; cin >> x;
        solve(x);
    }
}