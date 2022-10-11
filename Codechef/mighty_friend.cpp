#include <bits/stdc++.h>
using namespace std;

inline vector<int> swap(vector<int> &a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return a;
}

int get_sum(int motu, vector<int> a) {
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i % 2 == motu) c++; 
    }

    return c;
}

int solve(int k, vector<int> a, int i) {
    if (k == 0) {
        if (get_sum(0, a) > get_sum(1, a)) {
            return 1;
        }
        return 0;
    }

    for (int j = i; j < a.size(); j++) {
        return solve(k - 1, swap(a, i, j), i + 1);
    }
}

int main() {
    int t;
    int n;
    int k;

    cin >> t;

    while (t--) {
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (solve(k, a, 0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}