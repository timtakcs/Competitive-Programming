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

struct coord {
    int x;
    int y;
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
    setIO();

    int t; cin >> t;
    while(t--) {
        int s, p; cin >> s >> p;
        vector<coord> posts;
        vector<edge> edges;

        vector<int> link(p);
        vector<int> size(p);

        for (int i = 0; i < p; i++) {
            coord c;
            cin >> c.x >> c.y;
            posts.push_back(c);
            link[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                edge e;
                e.u = i;
                e.v = j;
                e.w = sqrt(pow(posts[i].x - posts[j].x, 2) + pow(posts[i].y - posts[j].y, 2));
                edges.push_back(e);
            }
        }

        vector<edge> mst;

        kruskal(edges, mst, link, size);

        cout << fixed << setprecision(2) << mst[mst.size() - s].w << endl;
    }
}