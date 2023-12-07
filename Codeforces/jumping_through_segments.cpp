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

bool is_possible(int mid, vector<ll> &l, vector<ll> &r) {
    int pos = 0;

}

ll binary_search(ll lo, ll hi, vector<ll> &l, vector<ll> &r) {
    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (is_possible(mid, l, r)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    setIO();
}