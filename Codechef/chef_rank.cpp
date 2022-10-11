#include <iostream>
using namespace std;

int get_ans(int x) {
    if (x % 25 == 0) return x / 25;
    return x / 25 + 1;
}

void solve() {
    int t;
    int x;

    cin >> t;

    for(int k = 0; k < t; k++) {
        cin >> x;
        cout << get_ans(x) << endl;
    }   
}

int main() {
    solve();
    return 0;
}