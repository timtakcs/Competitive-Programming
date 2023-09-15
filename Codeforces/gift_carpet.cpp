#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;

    while (t--) {
        int letter = 0;

        string name = "vika";

        int n, m; cin >> n >> m;
        vector<string> carpet(n);

        for (int i = 0; i < n; i++) {
            cin >> carpet[i];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (carpet[j][i] == name[letter]) {
                    letter++;
                    break;
                }
            }
        }

        if (letter == 4) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}