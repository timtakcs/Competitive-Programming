#include <iostream>

#define ll long long

using namespace std;

ll solve(ll g, ll p, ll h) {
    ll exp = 1;
    ll rem = g;

    while (rem != h) {
        exp++;
        rem = (rem * g) % p;
    }

    return exp;
}

int main() {
    ll g, p, h; cin >> g >> p >> h;

    cout << solve(g, p, h);
}