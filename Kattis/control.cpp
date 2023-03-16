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

int find(int x, map<int, int> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(int a, int b, map<int, int> &link, map<int, int> &size) {
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

int main() {
    setIO();

    int n; cin >> n;

    map<int, int> link;
    map<int, int> size;

    int potions = 0;

    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        int sum = 0;
        vector<int> ings;
        set<int> p;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            ings.push_back(x);

            if (!link.count(x)) {
                link[x] = x;
                size[x] = 1;
                p.insert(x);
                sum++;
            } else {
                int par = find(x, link);
                if (!p.count(par)) {
                    p.insert(par);
                    sum += size[par];
                }
            }
        }

        if (sum == m) {
            potions++;
            for (int k = 1; k < ings.size(); k++) {
                unite(ings[0], ings[k], link, size);
            }
        }
    }

    cout << potions << endl;
}