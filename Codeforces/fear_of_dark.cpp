#include <iostream>
#include<bits/stdc++.h>
#include <iomanip>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

bool overlap(int ax, int ay, int bx, int by, bool circle, double w) {
    double dist = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));

    if (circle) {
        if (dist <= 2 * w) return true;
        else return false;
    } else {
        if (dist <= w) return true;
        else return false;
    }
}

bool is_possible(int px, int py, int ax, int ay, int bx, int by, double w) {
    double ox = 0.0;
    double oy = 0.0;
    if (overlap(ax, ay, bx, by, true, w)) {
        if ((overlap(ox, oy, ax, ay, false, w) || overlap(ox, oy, bx, by, false, w)) 
            && (overlap(px, py, ax, ay, false, w) || overlap(px, py, bx, by, false, w))) return true;
        else return false;
    } else {
        if ((overlap(ox, oy, ax, ay, false, w) && overlap(px, py, ax, ay, false, w)) 
            || (overlap(ox, oy, bx, by, false, w) && overlap(px, py, bx, by, false, w))) return true;
        else return false;
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int px, py; cin >> px >> py;
        int ax, ay; cin >> ax >> ay;
        int bx, by; cin >> bx >> by;

        double l = 0;
        double h = (double)1e4;

        double ans = (double)1e4;
        double epsilon = 1e-10;
        while (h - l > epsilon) {
            double mid = (l + h) / 2;
            if (is_possible(px, py, ax, ay, bx, by, mid)) {
                ans = mid;
                h = mid;
            } else {
                l = mid;
            }
        }

        cout << fixed << setprecision(10) << ans << endl;
    }

}