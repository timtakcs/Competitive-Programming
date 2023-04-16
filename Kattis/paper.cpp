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

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int n; cin >> n;
    vector<int> a(n - 1); 
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    double small = pow(2, -1.25);
    double big = pow(2, -0.75);

    double start_small = small;
    double start_big = big;
   
    double total = 0;
    int need = 1; 

    for (int i = 0; i < n - 1; i++) {
        need *= 2;
        int take = min(need, a[i]);
        
        if (i != 0) {
            if (i % 2 == 0) {
                small /= 2;
            } else {
                big /= 2;
            }
        }

        if (need == take) {
            total += (small + big) * take * 2;
            need -= take;
            break;
        } else {
            total += (small + big) * take * 2;
            need -= take;
        }
    }

    if (need) cout << "impossible" << endl;
    else cout << ((total - (start_big + start_small*2)*2)/2.0) << endl;

}