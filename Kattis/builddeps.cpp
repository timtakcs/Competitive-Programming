#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

map<string, vector<string>> adj;
map<string, bool> vis;
vector<string> res;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void dfs(string &c) {
    if (vis[c]) return;

    vis[c] = true;

    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    res.pb(c);
}

int main() {
    setIO();

    int n; cin >> n;

    for (int i = 0; i < n + 1; i++) {
        string s; getline(cin, s);

        stringstream ss(s);
        string token;
        string key;

        if (getline(ss, token, ':')) {
            key = token;
            while (ss >> token) { 
                adj[token].push_back(key);
                vis[token] = false;
            }
        }

        vis[key] = false;
    }

    string c; cin >> c;

    dfs(c);

    reverse(res.begin(), res.end());

    for (auto x: res) {
        cout << x << endl;
    }
}