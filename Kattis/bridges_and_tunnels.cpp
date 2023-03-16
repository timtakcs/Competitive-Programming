#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

string find(string x, map<string, string> &link) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

void unite(string a, string b, map<string, string> &link, map<string, int> &size) {
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
    map<string, string> link;
    map<string, int> size;

    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;

        if (!size.count(a)) {
            size[a] = 1;
            link[a] = a;
        }
        if (!size.count(b)) {
            size[b] = 1;
            link[b] = b;
        }

        unite(a, b, link, size);
        cout << size[find(a, link)] << endl;
    }
}