#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if (((n * (n + 1))/2) % n == 0) cout << -1 << endl;
        else {
            vector<int> perm;
            for (int i = 1; i <= n; i++) {
                perm.push_back(i);
            }
            
            int sum = perm[0];
            for (int i = 1; i < n; i++) {
                sum += perm[i];
                if (sum % (i + 1) == 0) {
                    sum -= perm[i];
                    swap(perm, i, i+1);
                    sum += perm[i];
                }
            }

            for (int i = 0; i < n; i++) {
                cout << perm[i] << " ";
            }
            cout << endl;
        }
    }
}

// 1 3 6 10 15 21 28 36 45 55