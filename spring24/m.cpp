#include <iostream>
#include <bits/stdc++.h>
#include <map>
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

    int n, l, q; cin >> n >> l >> q;

    map<string, string> dict;

    for (int i = 0; i < n; i++) {
        string a, conv, b; cin >> a >> conv >> b;

        dict[a] = b;
    }

    vector<string> sentence(l);
    for (int i = 0; i < l; i++) {
        cin >> sentence[i];
    }

    for (int i = 0; i < q; i++) {
        vector<string> query(l);
        for (int j = 0; j < l; j++) {
            cin >> query[j];
            if (!dict.count(query[j])) dict[query[j]] = "???";
        }

        bool possible = true;

        for (int j = 0; j < l; j++) {
            if ((dict[query[j]] != sentence[j])) {
                possible = false;
                break;
            }
        }

        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}