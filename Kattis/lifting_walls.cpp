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
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

struct crane {
    float x;
    float y;
};

int main() {
    setIO();

    float l, w; cin >> l >> w;
    int n, r; cin >> n >> r;

    vector<crane> cranes;
    vector<float> wx = {-l/2, l/2, 0, 0};
    vector<float> wy = {0, 0, -w/2, w/2};
    vector<vector<int>> walls(4);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        crane cr;
        cr.x = x;
        cr.y = y;

        cranes.push_back(cr);    
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (sqrt(pow((wx[j] - cranes[i].x), 2.0) + pow((wy[j] - cranes[i].y),2.0)) <= r) {
                walls[j].push_back(i);
            }
        }
    }

    if (walls[0].size() == 0 || walls[1].size() == 0 || walls[2].size() == 0 || walls[3].size() == 0) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<vector<int>> reaching(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (count(walls[j].begin(), walls[j].end(), i)) {
                reaching[i].push_back(j);
            }
        }
    }

    set<int> cur;
    int ans = 4;

    for (int i = 0; i < n; i++) {
        if (reaching[i].size() == 4) ans = min(ans, 1);

        for (int j = 0; j < n; j++) {
            cur.clear();
            for (auto w: reaching[i]) cur.insert(w);
            for (auto w: reaching[j]) cur.insert(w);
            if (cur.size() == 4) ans = min(ans, 2);

            for (int k = 0; k < n; k++) {
                cur.clear();
                for (auto w: reaching[i]) cur.insert(w);
                for (auto w: reaching[j]) cur.insert(w);
                for (auto w: reaching[k]) cur.insert(w);
                if (cur.size() == 4) ans = min(ans, 3);
            }
        }
    }

    cout << ans << endl;
}