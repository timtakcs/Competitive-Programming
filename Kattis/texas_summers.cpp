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

ll dist(int x1, int y1, int x2, int y2) {
    return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
    setIO();

    int n; cin >> n;
    vector<pair<int, int>> v(n + 2);
    vector<vector<ll>> adj(n + 2, vector<ll>(n + 2));

    for(int i = 1; i < n + 1; i++) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
        adj[i][i] = 0.0;

        for (int j = 1; j < i; j++) {
            ll d = dist(a, b, v[j].f, v[j].s);
            adj[i][j] = d;
            adj[j][i] = d;
        }
    }

    ll a, b; cin >> a >> b;
    ll c, d; cin >> c >> d;

    v[0] = {a, b};
    v[n + 1] = {c, d};

    ll k = dist(a, b, c, d);
    adj[0][n + 1] = k;
    adj[n + 1][0] = k;

    for (int i = 1; i < n + 1; i++) {
        cout << v[i].f << " " << v[i].s << endl;

        ll d_dorm = dist(a, b, v[i].f, v[i].s);

        adj[i][0] = d_dorm;
        adj[0][i] = d_dorm;

        ll d_class = dist(c, d, v[i].f, v[i].s);
        adj[i][n + 1] = d_class;
        adj[n + 1][i] = d_class;
    }

    vector<ll> parent(n + 2);
    vector<ll> dist(n + 2, INF);
    vector<bool> vis(n + 2, false);

    parent[0] = -1;
    ll source = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    
    pq.push({0, source});

    while (pq.size()) {
        pair<ll, ll> curr = pq.top(); pq.pop();
        ll u = curr.s;
        ll w = curr.f;

        if (vis[u]) continue;

        vis[u] = true;

        for (int i = 0; i < n + 2; i++) {
            if (adj[u][i] != 0 && !vis[i] && dist[i] > adj[u][i]) {
                dist[i] = adj[u][i];
                pq.push({dist[i], i});
                parent[i] = u;
            }
        }
    }
    
    int cur = parent[n + 1];
    vector<int> path;
    while (parent[cur] != -1) {
        path.pb(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    if (path.size() == 0) cout << "-" << endl;
    else {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] - 1 << " ";
        }
        cout << endl;
    }
}