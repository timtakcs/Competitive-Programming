#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

int main() {
    int n; cin >> n;
    ll mx = 0;
    vector<ll> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        mx = max(mx, t[i]);
    }

    stack<int> s;

    for (int j = 0; j < n; j++) {
        if (!s.empty()) {
            if (s.top() == t[j]) {
                s.pop();
            }
            else {
                s.push(t[j]);
            }
        }
        else {
            s.push(t[j]);
        }
    }

    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
