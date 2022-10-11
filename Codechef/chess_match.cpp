#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int a, int b) { 
    return 2 * (n + 180) - a - b;
}

int main() {
    int t;
    int n;
    int a;
    int b;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> a;
        cin >> b;

        cout << solve(n, a, b) << endl;
    }
}