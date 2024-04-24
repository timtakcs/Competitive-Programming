#include <iostream>
#include <bits/stdc++.h>
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

vector<pii> get_valid_ranges(vector<pii> &ranges, int x) {
    vector<pii> ans;

    for (int i = 0; i < ranges.size(); i++) {
        if (ranges[i].f <= x && x <= ranges[i].s) {
            ans.push_back(ranges[i]);
        }
    }

    return ans;
}

int main() {
    setIO();

    int s, g; cin >> s >> g;

    vector<pii> ranges(g); 

    for (int i = 0; i < g; i++) {
        string s; cin >> s;
        int l, r; cin >> l >> r;

        ranges.push_back({l, r});
    }

    vector<int> a(s);
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }

    int ans = 0;

    vector<pii> valid_ranges = get_valid_ranges(ranges, a[0]);

    for (int i = 1; i < s; i++) {
        vector<pii> temp = get_valid_ranges(valid_ranges, a[i]);

        if (temp.size() == 0) {
            ans++;
            valid_ranges = get_valid_ranges(ranges, a[i]);
        }
    }

    cout << ans << endl;
}