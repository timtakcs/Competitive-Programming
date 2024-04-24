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

int main() {
    setIO();

    freopen("AOC23/input.txt", "r", stdin);
    freopen("AOC23/output.txt", "w", stdout);

    map<pii, vector<pii>> adj;

    string s;

    int i = 0;

    pii start;

    while (!cin.eof()) {
        cin >> s;

        for (int j = 0; j < s.length(); j++) {

            if (s[j] == 'S') {
                start = {i, j};
                continue;
            }

            switch (s[j]) {
                case '7':
                    adj[{i, j}].push_back({i + 1, j});
                    adj[{i, j}].push_back({i, j - 1});
                    break;
                case 'J':
                    adj[{i, j}].push_back({i - 1, j});
                    adj[{i, j}].push_back({i, j - 1});
                    break;
                case 'F':
                    adj[{i, j}].push_back({i + 1, j});
                    adj[{i, j}].push_back({i, j + 1});
                    break;
                case 'L':
                    adj[{i, j}].push_back({i - 1, j});
                    adj[{i, j}].push_back({i, j + 1});
                    break;
                case '-':
                    adj[{i, j}].push_back({i, j - 1});
                    adj[{i, j}].push_back({i, j + 1});
                    break;
                case '|':
                    adj[{i, j}].push_back({i + 1, j});
                    adj[{i, j}].push_back({i - 1, j});
                    break;
                default:
                    break;
            }
        }

        i++;
    }

    vector<vector<int>> dist(i, vector<int>(s.length(), -1));

    

}