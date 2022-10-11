#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int t;

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int k;
        int v;
        cin >> n >> k >> v;
        int a[n];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            sum += a[j];
        }

        int x = v * (n + k) - sum; 
        if (x > 0 && x % k == 0) cout << x/k << endl;
        else cout << "-1" << endl;
    }
}