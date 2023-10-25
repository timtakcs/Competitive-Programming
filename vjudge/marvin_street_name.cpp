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

    int n; cin >> n;

    ll sum = 0;
    string s = "a";
    int i = 0;

    while (sum <= n) {
        if (i % 2 == 0) s += 'z';
        else s += 'a';

        sum += 25;
        i++;
    }

    if (sum == n) {
        cout << s << endl;
        return 0;
    }

    if (n % 2 == 1) {
        if (s[s.size() - 1] == 'z') {
            s[s.size() - 1] = 'y';
            sum--;
        } else {
            s[s.size() - 1] = 'b';
            sum++;
        }
    }

    if (sum == n) {
        cout << s << endl;
        return 0;
    }

    while (sum > n) {
        s[1]--;
        if (s.size() == 2) sum--;
        else sum -= 2;

        cout << s << " " << sum << endl;
    }

    cout << s << endl;
}