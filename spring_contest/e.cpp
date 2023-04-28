#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin(), a.end(), greater<pii>());

    int frontier = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].s < frontier) {
            continue;
        } else {
            total += a[i].f * (a[i].s - frontier + 1);
            frontier = a[i].s + 1;
        }
    }
    
    cout << total << endl;

    
}