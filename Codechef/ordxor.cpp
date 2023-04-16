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
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int getmsb(int n){
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;

        int ans = 0;
        int count = 0;
        
        for (int i = 0; i < 30; i++) {

            cout << (a^i) << " " << (b^i) << " " << (c^i) << endl;

            if ((a^i) < (b^i)) {
                if ((b^i) < (c^i)) {
                    ans = i;
                    count++;
                }
            }
            if (ans != 0) break;
        }
        if (count == 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}