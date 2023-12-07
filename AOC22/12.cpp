#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

int get_ascii(char x) {
    return x - 'a' + 1;
}

int bfs(int start_x, int start_y, vector<vector<bool>> &visited, vector<string> &map, int x_end, int y_end) {
    queue<pair<pair<int, int>, int>> q;
    q.push(mp(mp(start_x, start_y), 0));
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        
        int x = cur.f.f;
        int y = cur.f.s;
        int depth = cur.s;

        if (x == x_end && y == y_end) {
            return depth;
        }

        for (int i = x - 1; i < x + 2; i += 2) {
            if (i < 0 || (i > map.size() - 1)) {
                continue;
            }

            if ((get_ascii(map[i][y]) - get_ascii(map[x][y]) < 2) && !visited[i][y]) {
                visited[i][y] = true;
                q.push(mp(mp(i, y), depth + 1));
            }
        }

        for (int j = y - 1; j < y + 2; j += 2) {
            if (j < 0 || (j > map[0].size() - 1)) {
                continue;
            }

            if ((get_ascii(map[x][j]) - get_ascii(map[x][y]) < 2) && !visited[x][j]) {
                visited[x][j] = true;
                q.push(mp(mp(x, j), depth + 1));
            }
        }
    }

    return -1;
}

int main() {
    ofstream fout (".out");
    ifstream fin ("elves.in");

    string line;
    vector<string> lines;
    while (getline(fin, line)) {
        lines.push_back(line);
    }

    int x_start;
    int y_start;

    vector<pair<int, int>> starts;

    int x_end;
    int y_end;

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] == 'S' || lines[i][j] == 'a') {
                starts.push_back(mp(i, j));
                lines[i][j] = 'a';
            }
            if (lines[i][j] == 'E') {
                x_end = i;
                y_end = j;
                lines[i][j] = 'z';
            }
        }
    } 

    int min_steps = 99999;

    for (auto &p: starts) {
        int x = p.f;
        int y = p.s;

        vector<vector<bool>> visited(lines.size(), vector<bool>(lines[0].size(), false));
        int steps = bfs(x, y, visited, lines, x_end, y_end);
        if (steps < 0) continue;
        min_steps = min(steps, min_steps); 
    }
    
    cout << min_steps << endl;

}