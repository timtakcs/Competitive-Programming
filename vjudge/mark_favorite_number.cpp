#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    ll l = 1;
    ll h = 1000;

    string inp = "";

    while (1 == 1) {
        ll mid = (l + h) / 2;
        cout << mid << endl;

        cin >> inp;

        if (inp == "correct") return 0;
        else if (inp == "lower") {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}