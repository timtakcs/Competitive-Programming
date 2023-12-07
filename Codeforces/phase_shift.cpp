#include <iostream>
#include <bits/stdc++.h>
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

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    if (size[a] > size[b]) {
        swap(a, b);
    } 
    link[b] = a;
    size[a] += size[b];                       
}

int main() {
    setIO();

    int t; cin >> t;

    string a = "abcdefghijklmnopqrstuvwxyz";

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> link(26);
        vector<int> size(26, 1);

        vector<int> in_deg(26, 0);
        vector<int> map(26, -1);

        for (int i = 0; i < 26; i++) {
            link[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';

            if (map[cur] != -1) continue;

            for (int j = 0; j < 26; j++) {
                if (in_deg[j] == 0 && (find(cur, link) != find(j, link) || size[find(cur, link)] == 26)){
                    map[cur] = j;
                    unite(cur, j, link, size);
                    in_deg[j]++;
                    break;
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += a[map[s[i] - 'a']];
        }

        cout << ans << endl;
    }
}