#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
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
    
    int n, q; cin >> n >> q;

    vector<int> link(n + 1);
    vector<int> size(n + 1);

    for (int i = 1; i < n + 1; i++) {
        size[i] = 1;
        link[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        char type; cin >> type;

        if (type == 't') {
            int a, b; cin >> a >> b;
            unite(a, b, link, size);
        } else if (type == 's') {
            int a; cin >> a;
            int x = find(a, link);
            cout << size[x] << endl;
        }
    }
}