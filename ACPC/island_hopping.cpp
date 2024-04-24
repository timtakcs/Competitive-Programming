#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

struct coord {
    double x;
    double y;
};

struct edge {
    int u;
    int v;
    float w;
};

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    if (size[a] > size[b]) {
        size[a] += size[b];
        link[b] = a;
    } else {
        size[b] += size[a];
        link[a] = b;
    }
}

bool comp(edge &e1, edge &e2) {
    return e1.w < e2.w;
}

void kruskal(vector<edge> &edges, vector<edge> &mst, vector<int> &link, vector<int> &size) {
    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < edges.size(); i++) {
        if (find(edges[i].u, link) != find(edges[i].v, link)) {
            unite(edges[i].u, edges[i].v, link, size);
            mst.push_back(edges[i]);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;

        vector<coord> posts;
        vector<edge> edges;

        vector<int> link(m);
        vector<int> size(m);

        for (int i = 0; i < m; i++) {
            coord c;
            cin >> c.x >> c.y;
            posts.push_back(c);
            link[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                edge e;
                e.u = i;
                e.v = j;
                e.w = sqrt(pow(posts[i].x - posts[j].x, 2) + pow(posts[i].y - posts[j].y, 2));
                edges.push_back(e);
            }
        }

        vector<edge> mst;

        kruskal(edges, mst, link, size);

        long double ans = 0;

        for (auto e: mst) {
            ans += e.w;
        }

        cout << fixed << setprecision(10) << ans << endl;
    }
}