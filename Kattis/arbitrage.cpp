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

bool cycle_bellman_ford(vector<vector<pair<int, double>>> &adj, int n, vector<double> &dist) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (auto e: adj[i]) {
                int u = e.f;
                double w = e.s;

                if (dist[i] + w < dist[u]) {
                    dist[u] = dist[i] + w;
                }
            }
        }
    }

    bool cycle = false;

    for (int i = 0; i < n; i++) {
        for (auto e: adj[i]) {
            int u = e.f;
            double w = e.s;

            if (dist[i] + w < dist[u]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    setIO();

    int n; cin >> n;
    
    while (n > 0) {
        map<string, int> names;
        for (int i = 0; i < n; i++) {
            string name; cin >> name;
            names[name] = i;
        }

        int m; cin >> m;
        vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());

        for (int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            string temp; cin >> temp;

            double lhs, rhs;

            string cur = "";
            for (int j = 0; j < temp.length(); j++) {
                if (temp[j] == ':') {
                    lhs = stod(cur);
                    cur = "";
                } else {
                    cur += temp[j];
                }
            }
            rhs = stod(cur);

            adj[names[a]].pb(mp(names[b], -log(rhs / lhs)));
            adj[names[b]].pb(mp(names[a], -log(lhs / rhs)));
        }

        vector<double> dist(n, INF);
        dist[0] = 0;
        bool cycle = cycle_bellman_ford(adj, n, dist);

        if (cycle) {
            cout << "Arbitrage" << endl;
        } else {
            cout << "Ok" << endl;
        }

        cin >> n;
    }
}