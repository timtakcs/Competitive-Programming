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

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> in_deg(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].push_back(b-1);
        in_deg[b-1]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (q.size()) {
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for (auto u: adj[curr]) {
            in_deg[u]--;
            if (in_deg[u] == 0) {
                q.push(u);
            }
        }
    }

    if (ans.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto u: ans) {
            cout << u + 1 << endl;
        }
    }
}