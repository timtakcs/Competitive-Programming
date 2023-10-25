#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

using namespace std;

bool is_possible(int mid) {return true;}

ll binary_search(ll l, ll h, vector<ll> &a, ll k) {
    ll ans = 0;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (is_possible(mid)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}