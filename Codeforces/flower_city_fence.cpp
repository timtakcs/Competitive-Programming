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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        } 

        if (a[0] != n) {
            cout << "NO" << endl;
            continue;
        }  

        vector<int> b;

        for (int i = n - 1; i >= 0; i--) {
            while (b.size() < a[i]) {
                b.push_back(i + 1);
            }
        }

        bool works = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                works = false;
                break;
            }
        }

        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

// int even = 0;
// for (int i = 0; i < size; i++) {
//     if ((*q) % 2 == 0) even++;
//     *q++;
// }
// return even;