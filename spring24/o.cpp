#include <iostream>
#include <bits/stdc++.h>
#include <set>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

pair<double, double> f(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;

    double size = sqrt(dx * dx + dy * dy);

    return {dx / size, dy / size};
}

int main() {
    setIO();

    int n, x, y; cin >> n >> x >> y;

    set<pair<double, double>> angles;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;

        pair<double, double> an = f(x, y, a, b);

        angles.insert(an);
    }

    cout << angles.size() << endl;
}