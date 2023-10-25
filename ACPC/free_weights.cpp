#include <iostream>
#include<bits/stdc++.h>
#include <set>
#include <map>
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


int main() {
    setIO();

    int n; cin >> n;

    map<int, int> cnt1;
    map<int, int> cnt2;

    vector<int> a(n);
    vector<int> b(n);

    set<int> r1;
    set<int> r2;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt1[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt2[b[i]]++;
    }

    ll ans = 0;
    
    for (auto x: cnt1) {
        if (x.second == 1) {
            ans = max(ans, (ll)x.first);
        }
    }

    r1.insert(a[0]);
    for (int i = 1; i < n; i++) {
        if (cnt1[a[i]] == 1) continue;

        if (r1.find(a[i]) != r1.end()) {
            if (r1.size() > 1){
                auto e = r1.end();
                e--; e--;
                ans = max(ans, (ll)*e);
            }
            r1.erase(a[i]);
        } else {
            r1.insert(a[i]);
        }
    }

    r2.insert(b[0]);
    for (int i = 1; i < n; i++) {
        if (cnt2[b[i]] == 1) continue;

        if (r2.find(b[i]) != r2.end()) {
            if (r2.size() > 1){
                auto e = r2.end();
                e--; e--;
                ans = max(ans, (ll)*e);
            }
            r2.erase(b[i]);
        } else {
            r2.insert(b[i]);
        }
    }

    cout << ans << endl;
}