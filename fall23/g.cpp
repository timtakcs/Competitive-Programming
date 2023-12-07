#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

int main() {
    string p = "aaaaaaaaaaaaaaaaaaaa";
    string a = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 20; i++) {
        int mn = 0;
        int min_score = 0;
        for (int j = 0; j < 26; j++) {
            cout << p << endl;
            cout << flush;

            int x; cin >> x;

            if (x == 0) return 0;

            if (x < min_score) {
                min_score = x;
                mn = j;
            }

            p[i] = a[j];
        }

        p[i] = a[mn];
    }
}