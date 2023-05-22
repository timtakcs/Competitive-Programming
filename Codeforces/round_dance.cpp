#include <iostream>
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

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int find(int x, vector<int> &link) {
    while (x != link[x]) {
        link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}

void unite(int a, int b, vector<int> &link, vector<int> &size, int &num_sets) {
    a = find(a, link);
    b = find(b, link);

    if (a == b) return;

    num_sets--;

    if (size[a] > size[b]) {
        swap(a, b);
    } 
    link[b] = a;
    size[a] += size[b];                       
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> link(n + 1);
        vector<int> size(n + 1);

        for (int i = 1; i < n + 1; i++) {
            size[i] = 1;
            link[i] = i;
        }

        int num_sets = n;
        vector<int> out_deg(n + 1, 0);

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (!(find(i + 1, link) == find(a[i], link))) {
                out_deg[i + 1]++;
                out_deg[a[i]]++;
            }

            unite(i + 1, a[i], link, size, num_sets);
        }

        int upper_bound = num_sets;

        vector<int> hanging;

        for (int i = 1; i < n + 1; i++) {
            if (out_deg[i] == 1) {
                hanging.pb(i);
            }
        }

        // for (int i = 0; i < hanging.size(); i++) {
        //     cout << hanging[i] << " ";
        // }
        // cout << endl;

        bool united = false;
        while (!united) {
            united = true;

            if (hanging.size() == 0) break;

            int first = hanging[0];
            for (int i = 1; i < hanging.size(); i++) {
                if (find(first, link) != find(hanging[i], link)) {

                    cout << first << " " << hanging[i] << endl;

                    unite(first, hanging[i], link, size, num_sets);
                    hanging.erase(hanging.begin() + i);
                    hanging.erase(hanging.begin());
                    united = false;
                    break;
                }
            }
        }

        int lower_bound = num_sets;

        cout << lower_bound << " " << upper_bound << endl;
    }
}