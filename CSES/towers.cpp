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

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int binary_search(int x, vector<int> &a) {
    int l = 0;
    int h = a.size() - 1;

    while (l < h) {
        int mid = (l + h) / 2;

    }
}

int main() {
    setIO();

    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int l = 0;
        int h = ans.size();

        while (l < h) {
            int mid = (l + h) / 2;
            if (ans[mid] > a[i]) h = mid;
            else l = mid + 1;
        }

        if (l == ans.size()) ans.push_back(a[i]);
        else ans[l] = a[i];
    }

    cout << ans.size() << endl;
}