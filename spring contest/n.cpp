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

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

pii find(pii x, map<pii, pii> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(pii a, pii b, map<pii, pii> &link, map<pii, int> &size) {
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

    vector<string> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    map<pii, pii> link;
    map<pii, int> size;

    vector<pii> open;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == '\\') {
                pii a = {i, j};
                pii b = {i + 1, j + 1};

                unite(a, b, link, size);
            } else if (m[i][j] == '/') {
                pii a = {i, j + 1};
                pii b = {i + 1, j};
            } else {
                open.pb({i, j});
            }
        }
    }

    vector<string> ans(n, string(n, ' '));

    map<pii, pii> copy_link;
    map<pii, int> copy_size;

    for (int i = 0; i < open.size(); i++) {
        pii square = open[i];
        int right = 0;
        int left = 0;

        pii a = {square.f, square.s};
        pii b = {square.f + 1, square.s + 1};

        copy_link = link;
        copy_size = size;

        unite(a, b, copy_link, copy_size);
        if (find({0, 0}, copy_link) == find(a, copy_link)) {
            right = copy_size[find(a, copy_link)];
        }

        pii c = {square.f, square.s + 1};
        pii d = {square.f + 1, square.s};

        copy_link = link;
        copy_size = size;

        unite(c, d, copy_link, copy_size);
        if (find({0, 0}, copy_link) == find(c, copy_link)) {
            left = copy_size[find(c, copy_link)];
        }

        if (right > left) {
            m[a.f][a.s] = '\\';
        } else {
            m[a.f][a.s] = '/';
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << m[i] << endl;
    }
}