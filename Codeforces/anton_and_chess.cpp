#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

bool check_straight(int kx, int ky, int dx, int dy, int x, int y, vector<vector<bool>> &occ) {
    if (ky == y) {
        while (kx != x) {
            if (occ[kx][ky]) return false;
            kx += dx;
        }
    }
    else {
        while (ky != y) {
            if (occ[kx][ky]) return false;
            ky += dy;
        }
    }
    return true;
}

bool check_diag(int kx, int ky, int dx, int dy, int x, int y, vector<vector<bool>> &occ) {
    while (kx != x && ky != y) {
        if (occ[kx][ky]) return false;
        kx += dx;
        ky += dy;
    }

    return true;
}

int main() {
    ll n; cin >> n;
    ll kx; ll ky; cin >> kx >> ky;
    vector<vector<bool>> occ(n);
    map<char, vector<pair<int, int>>> m;

    m['R'] = {};
    m['B'] = {};

    for (int i = 0; i < n; i++) {
        char piece; cin >> piece;
        ll px; ll py; cin >> px >> py;
        pair coords = mp(px, py);
        occ[px][py] = true;
        if (piece == 'Q') {
            m['R'].push_back(coords);
            m['B'].push_back(coords);
        }
        else {
            m[piece].push_back(coords);
        }
    }

    bool check = false;

    for (auto &r: m['R']) {
        int x = r.first;
        int y = r.second;
        int dx = (x - kx)/abs(x - kx);
        int dy = (y - ky)/abs(y - ky);
        if (x == kx || y == ky) check = check_straight(kx, ky, dx, dy, x, y, occ);
    }

    for (auto &b: m['B']) {
        int x = b.first;
        int y = b.second;
        int dy = y - ky;
        int dx = x - kx;
        if (abs(dy) == abs(dx)) check = check_diag(kx, ky, dx/abs(dx), dy/abs(dy), x, y, occ);
    }

    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;
}