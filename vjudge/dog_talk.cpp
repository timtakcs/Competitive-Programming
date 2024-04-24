#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <queue>
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

vector<string> tokenize(string &line) {
    vector<string> res;
    string cur = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            res.push_back(cur);
            cur = "";
        }
        else {
            cur += line[i];
            continue;
        }
    }

    res.push_back(cur);

    return res;
}

bool bfs(map<string, vector<string>> &adj, string src, string dst) {
    queue<string> q;
    map<string, bool> vis;

    q.push(src);
    vis[src] = true;

    while (q.size()) {
        string u = q.front(); q.pop();

        if (u == dst) return true;

        for (auto n: adj[u]) {
            if (!vis[n]) {
                vis[n] = true;
                q.push(n);        
            }
        }
    }

    return false;
}

int main() {
    setIO();

    int n; cin >> n;
    map<string, vector<string>> adj;
    string s;
    for (int i = 0; i < n + 1; i++) {
    
        getline(cin, s);

        vector<string> cur = tokenize(s);

        adj[cur[0]].push_back(cur[cur.size() - 1]);
    }

    if (bfs(adj, "cats", "great")) {
        cout << "Cats are great! :D" << endl;
    } else {
        cout << "Cats are not great :(" << endl;
    }

}