#include <iostream>
#include <bits/stdc++.h>
#include <map>
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

int mx;

bool is_possible(vector<int> &a, map<int, int> &cnt, ll k, ll cuts) {
    vector<int> temp;
    int avb = 0;
    for (int i = 1; i < mx; i++) {
        avb = min(k -(ll)temp.size(), cnt[i] / cuts);
        for (int j = 0; j < avb; j++) {
            temp.push_back(i);
        }
    }

    return temp.size() == k;

} 

ll binary_search(ll l, ll h, vector<int> &a, map<int, int> &cnt, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(a, cnt, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return ans;
}

int main() {
    setIO();

    int n, k; cin >> n >> k;

    mx = 0;

    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    ll l = 0;
    ll h = 2e5 + 1;
    ll ans = binary_search(l, h, a, cnt, (ll)k);

    ll temp = 0;
    int avb = 0;
    for (int i = 1; i < mx; i++) {
        avb = min(k - temp, cnt[i] / ans);
        for (int j = 0; j < avb; j++) {
            cout << i << " ";
            temp++;
        }
    }
}