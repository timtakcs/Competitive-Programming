#include <iostream>
#include <bits/stdc++.h>
#include <set>
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

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

bool is_sorted(vector<int> &a, int n) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            sorted = false;
        }
    }

    return sorted;
}

bool sorted_revese(vector<int> &a, int n) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (a[n - 1 - i] > a[n - i - 2]) {
            sorted = false;
        }
    }

    return sorted;
}

bool sorted_right_shift(vector<int> &a, int n) {
    int temp = a.back();
    a.pop_back();
    a.insert(a.begin(), temp);

    return is_sorted(a, n);
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (is_sorted(a, n)) {
            cout << 0 << endl;
        } else if (sorted_revese(a, n)) {
            cout << a[0] << endl;
        } else if (a[n - 1] < a[0] && sorted_right_shift(a, n)) {
            cout << a[0] << endl;
        } else {
            cout << -1 << endl;
        }        
    }
}