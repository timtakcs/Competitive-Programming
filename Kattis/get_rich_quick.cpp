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

vector<int> num_s(305);

bool comp(int a, int b) {
    return num_s[a] < num_s[b];
}

int main() {
    int n; cin >> n;

    vector<vector<int>> c;

    for (int i = 0; i < n; i++) {
        int p, m; cin >> p >> m;

        c.push_back({p, m});
    }

    int s; cin >> s;

    map<int, vector<int>> items;    
    vector<int> order;
    vector<int> prices;

    for (int i = 0; i < s; i++) {
        int l, a; cin >> l >> a;

        order.push_back(i);
        num_s[i] = a;
        prices.push_back(l);

        for (int j = 0; j < a; j++) {
            int k; cin >> k;
            items[i].push_back(k-1);
        }

        sort(items.begin(), items.end(),
          [](int a, int b) {return a < b;});
    }

    sort(order.begin(), order.end(), comp);

    int sum = 0;

    for (int i = 0; i < s; i++) {
        int num = 0;
    }
}