#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

class comp{
public:
    bool operator() (vector<pair<pair<int, int>, int>> a, vector<pair<pair<int, int>, int>> b) {
        return a.back().f.f > b.back().f.f;
    }
};

vector<int> dijkstra(vector<vector<int>> &adj_list, vector<vector<int>> &adj_matx, int k, int n) {
    int met = n;
    vector<int> sums;
    priority_queue< vector<pair<pair<int, int>, int>>, vector<vector<pair<pair<int, int>, int>>>, comp > pq;

    pq.push({mp(mp(0, 1), 0)});

    while(!pq.empty() && sums.size() < k) {
        vector<pair<pair<int, int>, int>> p = pq.top();
        pq.pop();
        pair<pair<int, int>, int> cur = p.back();
        int v = cur.f.s; int total = cur.s;

        for (auto &nb : adj_list[v]) {
            if (nb == met) {
                sums.push_back(adj_matx[v][nb] + total);
                continue;
            }
            else {
                vector<pair<pair<int, int>, int>> copy = p;
                vector<pair<pair<int, int>, int>> n;
                n.push_back(mp(mp(adj_matx[v][nb], nb), adj_matx[v][nb] + total));
                p.insert(p.end(), n.begin(), n.end());
                pq.push(p);
                p = copy;
            }
        }
    }

    return sums;
}

int main() {
    int n; int m; int k;
    cin >> n >> m >> k;

    vector<vector<int>> adj_list(n + 1);
    vector<vector<int>> adj_matx(n + 1, vector<int> (n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a; int b; int w;
        cin >> a >> b >> w;
        adj_list[a].push_back(b);
        adj_matx[a][b] = w;
    }

    vector<int> res = dijkstra(adj_list, adj_matx, k, n);
    sort(res.begin(), res.end());

    for (auto &r : res) {
        cout << r << " ";
    }
}