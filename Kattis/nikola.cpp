#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
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

struct p {
    int k;
    int cost;
    int last;
};

struct comp {
    bool operator()(p &lhs, p &rhs) {
        return lhs.cost > rhs.cost;
    }
};

int main() {
    setIO();

    int n; cin >> n;
    vector<int> arr(2000);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i + 1];
    }

    priority_queue<p, vector<p>, comp> pq;
    set<pair<int, int>> vis;

    pq.push({2, arr[2], 1});
    vis.insert({2, 1});

    while (pq.size()) {
        p cur = pq.top(); pq.pop();
        if (cur.k == n) {
            cout << cur.cost << endl;
            return 0;
        } else {
            if (cur.k + cur.last + 1 <= n && vis.find({cur.k + cur.last + 1, cur.last + 1}) == vis.end()) {
                pq.push({cur.k + cur.last + 1, cur.cost + arr[cur.k + cur.last + 1], cur.last + 1});
                vis.insert({cur.k + cur.last + 1, cur.last + 1});
            }
            if (cur.k - cur.last >= 1 && vis.find({cur.k - cur.last, cur.last}) == vis.end()) {
                pq.push({cur.k - cur.last, cur.cost + arr[cur.k - cur.last], cur.last});
                vis.insert({cur.k - cur.last, cur.last});
            }
        }
    }
}