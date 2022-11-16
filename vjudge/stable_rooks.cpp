#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair

void set_board(vector<vector<char>> &b, int k) {
    int rc = 0;
    int count = k;
    while(count) {
        b[rc][rc] = 'R';
        rc += 2;
        count--;
    }
}

void print_board(vector<vector<char>> &b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j]; 
        }
        cout << "\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; int k; cin >> n >> k;
        vector<vector<char>> b(n, vector<char>(n, '.'));
        if (n / 2 + (n % 2) >= k) {
            set_board(b, k);
            print_board(b, n);
        }
        else cout << "-1" << endl;
    }
}