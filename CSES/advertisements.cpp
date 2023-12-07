#include <iostream>
#include <bits/stdc++.h>
#include <stack>
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> l;
    vector<int> r(n);

    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (s.size() && a[s.top()] >= a[i]) {
            s.pop();
        }

        if (!s.size()) l.push_back(-1); 
        else l.push_back(s.top());

        s.push(i);
    }

    stack<int> ss;

    for (int i = 0; i < n; i++) {
        while (ss.size() && a[ss.top()] > a[i]) {
            r[ss.top()] = i;
            ss.pop();
        }

        ss.push(i);
    }

    while (ss.size()) {
        r[ss.top()] = n;
        ss.pop();
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, (ll)a[i] * ((ll)r[i] - (ll)l[i] - 1LL));
    }

    cout << ans << endl;
}