#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        vector<int> out(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            out[a-1]++;
            out[b-1]++;

            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }

        // find the unique element in out
        map<int, int> count;
        for (int i = 0; i < n; i++) {
            if (count.count(out[i])) count[out[i]]++;
            else count[out[i]] = 1;
        }

        int unique = -1;

        for (auto i: count) {
            if (i.s == 1) {
                unique = i.f;
                break;
            }
        }

        int center = -1;

        if (unique == -1) {
            int max = 0;
            for (int i = 0; i < n; i++) {
                if (out[i] > max) {
                    max = out[i];
                    center = i;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (out[i] == unique) {
                    center = i;
                    break;
                }
            }
        }

        cout << adj[center].size() << " " << adj[adj[center][0]].size() - 1 << endl;
    }
}