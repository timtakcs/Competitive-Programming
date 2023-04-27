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

    int n = 0;
    int m = 0;
    cin >> n >> m;

    while (n != 0 && m != 0) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < m; i++) {
            int a = 0;
            int b = 0;
            double c = 0;
            cin >> a >> b >> c;
            adj[a].pb(mp(b, c));
            adj[b].pb(mp(a, c));
        }

        vector<double> dist(n, 0);
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq;
        pq.push(mp(1, 0));
        dist[0] = 1;

        while (!pq.empty()) {
            int curr = pq.top().s;
            pq.pop();

            if (visited[curr]) continue;
            visited[curr] = true;

            for (auto i : adj[curr]) {
                int next = i.f;
                double weight = i.s;
                if (dist[next] < dist[curr] * weight) {
                    dist[next] = dist[curr] * weight;
                    pq.push(mp(dist[next], next));
                }
            }
        }

        cout << fixed << setprecision(4) << dist[n-1] << endl;

        cin >> n >> m;
    }
}