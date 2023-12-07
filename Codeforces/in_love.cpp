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

int main() {
    setIO();

    int n; cin >> n;

    multiset<int> l;
    multiset<int> r;

    for (int i = 0; i < n; i++) {
        char op; cin >> op;
        int a, b; cin >> a >> b;

        if (op == '-') {
            auto lb = l.find(a);
            auto rb = r.find(b);

            l.erase(lb);
            r.erase(rb);
        } else {
            l.insert(a);
            r.insert(b);
        }

        if (l.size() <= 1) {
            cout << "NO" << endl;
            continue;
        }

        auto left = l.end();
        left--;

        int left_most = *left;

        auto right = r.begin();

        int right_most = *right;

        if (right_most < left_most) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}