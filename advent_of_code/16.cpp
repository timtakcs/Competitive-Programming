#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

struct node {
    string name;
    int flow_rate;
    vector<string> children;
};

vector<string> tokenize(string line) {
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

node make_node(string line) {
    vector<string> tokens = tokenize(line);

    string name = tokens[1];
    string num = "";

    for (int i = 5; i < tokens[5].length(); i++) {
        num += tokens[4][i];
    }

    int flow_rate = stoi(num);

    vector<string> children;

    for (int j = 9; j < tokens.size(); j++) {
        string child = "";
        child += tokens[j][0];
        child += tokens[j][1];
        children.push_back(child);
    }

    node * n = new node();
    n -> name = name;
    n -> flow_rate = flow_rate;

    return *n;
}

int wait(int time, int elapsed, int total, map<string, bool> &open, map<string, int> &flow_rates) {
    int left = time - elapsed;

    int rate = 0;
    for (auto &v : open) {
        if (v.second) {
            rate += flow_rates[v.first];
        }
    }

    return left * rate + total;
}
    

int dijkstra(string start, string end, map<string, vector<string>> &adj) {
    map<string, int> dist;
    map<string, string> prev;

    for (auto &p : adj) {
        dist[p.first] = 999999;
        prev[p.first] = "";
    }

    dist[start] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    pq.push(mp(0, start));

    while (!pq.empty()) {
        pair<int, string> cur = pq.top();
        pq.pop();

        int cur_dist = cur.first;
        string cur_node = cur.second;

        if (cur_dist > dist[cur_node]) continue;

        for (auto &n : adj[cur_node]) {
            int alt = dist[cur_node] + 1;
            if (alt < dist[n]) {
                dist[n] = alt;
                prev[n] = cur_node;
                pq.push(mp(alt, n));
            }
        }
    }

    return dist[end];
}

void sort_by_flow_rate(vector<node> &node_list) {
    sort(node_list.begin(), node_list.end(), [](node &a, node &b) {
        return a.flow_rate > b.flow_rate;
    });
}

int get_max_relieved(string cur, map<string, int> &shortest, map<string, bool> &open, map<string, int> &flow_rates, int total, int time) {
    vector<string> closed;
    for (auto &v : open) {
        if (!v.second) {
            closed.push_back(v.first);
        }
    }

    total += flow_rates[cur];

    int max_total = 0;

    for (auto &v : closed) {
        int cost = shortest[cur + v] + 1;
        if (time + cost > 30) {
            return wait(30, time, total, open, flow_rates);
        }
        else {
            total = wait(time + cost, time, total, open, flow_rates);

            open[v] = true;
            max_total = max(total + get_max_relieved(v, shortest, open, flow_rates, total, time + shortest[cur + v] + 1), max_total);
            open[v] = false;
        }
    }

    return max_total;
}

int main() {
    ofstream fout (".out");
    ifstream fin ("elves.in");

    string line;
    vector<string> lines;
    while (getline(fin, line)) {
        lines.push_back(line);
    }

    vector<node> node_list;

    for (auto line: lines) {
        node n = make_node(line);
        node_list.push_back(n);
    }

    map<string, vector<string>> adj;

    for (auto &n : node_list) {
        for (auto c : n.children) {
            adj[n.name].push_back(c);
        }
    }

    map<string, int> shortest_path;
    map<string, int> flow_rates;

    cout << dijkstra("AA", "CC", adj) << "fdfd" << endl;

    for (auto &n : node_list) {
        flow_rates[n.name] = n.flow_rate;
        for (auto &c : node_list) {
            if (n.name != c.name) {
                shortest_path[n.name + c.name] = dijkstra(n.name, c.name, adj);
            }
        }
    }

    map<string, bool> open;

    for (auto &n: node_list) {
        open[n.name] = false;
    }

    cout << get_max_relieved("AA", shortest_path, open, flow_rates, 0, 0) << endl;


}