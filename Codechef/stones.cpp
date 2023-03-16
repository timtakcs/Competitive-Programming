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
    while(t--){
        int n; cin >>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        
        if (n == 1) cout << "Marichka" << endl;
        else {
            bool x = false;
            for (int i = 0; i < n - 1; i+=2) {
                if (a[i] == a[i + 1]) continue;
                else {
                    x = true;
                    cout << "Marichka" << endl;
                    break;
                }
            }
            if (!x) cout << "Zenyk" << endl;
        }
    }
}