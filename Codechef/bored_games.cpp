//O(1) time and space complexity

#include <iostream>
using namespace std;

int solve(int n) {

    int k = (n % 2) ? (n + 1) / 2 : n / 2;

    if (n % 2 == 0) return 1 + ((2 * k * (k + 1) * (2 * k + 1))/3);

    return (n * (2 * k + 1) * (2 * k - 1))/3;
}

int main() {
    int t;
    int n;

    cin >> t;

    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}