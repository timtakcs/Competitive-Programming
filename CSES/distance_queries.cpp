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
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void euler_tour(vector<int> &first, vector<int> &traversal, vector<int> &depth, vector<bool> &vis, vector<vector<int>> &tree, int node, int d) {
    traversal.push_back(node);
    depth.push_back(d);
    vis[node] = true;

    for (auto child: tree[node]) {
        if (!vis[child]) {

            

            euler_tour(first, traversal, depth, vis, tree, child, d+1);
            traversal.push_back(node);
            depth.push_back(d);
        }
    }

}   

int main() {
    setIO();

    int n, q; cin >> n >> q;
    vector<vector<int>> tree(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    
    vector<int> depth;
    vector<int> traversal;
    vector<int> first;
    vector<bool> vis(n, false);
    
    euler_tour(first, traversal, depth, vis, tree, 0, 0);

    for (auto t: depth) {
        cout << t << " ";
    }

    for (int k = 0; k < q; k++) {
        int c,d; cin >> c >> d;    
    }
}