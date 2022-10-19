#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int q;
    char c;

    cin >> n >> q;

    vector<vector<long>> x(n, vector<long>(n, 0));
    vector<vector<long>> s(n, vector<long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '*') x[i][j] = 1;
            else x[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        long counter = 0;
        for (int j = 0; j < n; j++) {
            counter += x[i][j];
            if (i == 0) s[i][j] = counter;
            else s[i][j] = counter + s[i - 1][j];
        }
    }

    while (q--) {
        int x1; int y1; int x2; int y2; 
        cin >> y1 >> x1 >> y2 >> x2;

        // x1--; x2--; y1--; y2--;
        
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << endl;
    }
}