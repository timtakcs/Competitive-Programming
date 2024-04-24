#include <iostream>
#include <set>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<ll, ll>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    int n; cin >> n;

    vector<pii> order;
    set<pii> points;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        order.push_back({x, y});
    }

    sort(order.begin(), order.end(), greater<pii>());

    ll ans = 8000000000000000001;
    ll window = floor(sqrt(ans));

    for (int i = 0; i < n; i++) {
        int x = order[i].f;
        int y = order[i].s;

        auto start = points.lower_bound({y - window, x});

        for (auto it = start; it != points.end(); it++) {

            if (it->first > y + window) {
                break;
            }

            if (it->second < x - window) {
                points.erase(it);
            } else {
                ans = min(ans, ((y - it->first) * (y - it->first) + (x - it->second) * (x - it->second)));
            }
        }

        window = floor(sqrt(ans));
        points.insert({y, x});
    }

    cout << ans << endl;

}