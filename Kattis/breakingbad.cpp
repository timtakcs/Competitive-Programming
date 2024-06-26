#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
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

bool bipartile(int &idx, map<string, vector<string>> &adj, vector<set<string>> &sets, string src, map<string, bool> &vis) {
    queue<string> q;
    q.push(src);
    sets[0].insert(src);

    while (q.size()) {
        string v = q.front();
        q.pop();

        vis[v] = true;

        int idx = !(sets[0].count(v) > 0);

        for (auto u: adj[v]) {
            if (!sets[!idx].count(u) && !sets[idx].count(u)) {
                sets[!idx].insert(u);
                q.push(u);
            } else if (sets[idx].count(u)){
                return false;
            }https://www.google.com/url?sa=i&url=https%3A%2F%2Fsteamcommunity.com%2Fsharedfiles%2Ffiledetails%2F%3Fid%3D1195180273&psig=AOvVaw0x8r8VYX6nBlC8TLtu1whw&ust=1709939078418000&source=images&cd=vfe&opi=89978449&ved=0CBMQjRxqFwoTCOCc6Myh44QDFQAAAAAdAAAAABAD
        }
    }

    return true;
}

int main() {
    setIO();

    int n; cin >> n;
    vector<string> a(n);
    map<string, bool> vis;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = false;
    }

    int m; cin >> m;
    map<string, vector<string>> adj;

    for (int i = 0; i < m; i++) {
        string a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int idx = 0;
    vector<set<string>> sets(2);
    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (!vis[a[i]]) {
            if (!bipartile(idx, adj, sets, a[i], vis)) {
                possible = false;
                cout << "impossible" << endl;
                break;
            }
        }
    }
    if (possible) {
        for (auto s: sets) {
            for (auto x: s) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}