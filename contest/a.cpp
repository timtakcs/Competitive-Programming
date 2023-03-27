#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9 + 1;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int operations = INF;
        vector<int> ops(2, INF);
        for (int i = 0; i < n; i++) {
            ops[0] = INF;
            ops[1] = INF;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                int dif = abs(a[i] - a[j]);
                if (dif < ops[0]) {
                    ops[1] = ops[0];
                    ops[0] = dif;
                } else if (dif < ops[1]) ops[1] = dif;
            }
            operations = min(operations, ops[0] + ops[1]);
        }

        cout << operations << endl;
    }
    
}