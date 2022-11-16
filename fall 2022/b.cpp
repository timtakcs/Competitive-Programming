#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

void remove(vector<string> &all, string s) {
    for (int i = 0; i < all.size(); i++) {
        if (all[i] == s) all.erase(all.begin() + i);
    }
}

int main() {
    int n; int m; cin >> n >> m;
    vector<vector<string>> seqs;
    vector<string> all(n);

    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }

    for (int i = 0; i < m; i++) {
        int x; cin>>x;
        seqs.push_back(vector<string>(x));
        for (int j = 0; j < x; j++) {
            cin >> seqs[i][j];
        }
    }

    for (auto &s: seqs) {
        for (auto &p : s) {
            cout << p << " ";
            remove(all, p);
        }
    }

    for (auto &c : all) {
        cout << c << " ";
    }


}