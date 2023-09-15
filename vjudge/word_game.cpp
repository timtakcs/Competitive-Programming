#include <iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<map<string, int>> m(3, map<string, int>());
        set<string> ws;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                string s; cin >> s;
                ws.insert(s);

                m[i][s]++;
            }
        }

        vector<int> scores(3, 0);

        for (auto w: ws) {
            int count = m[0][w] + m[1][w] + m[2][w];

            if (count == 1) {
                for (int i = 0; i < 3; i++) {
                    if (m[i][w]) scores[i] += 3;
                }
            } else if (count == 2) {
                for (int i = 0; i < 3; i++) {
                    if (m[i][w]) scores[i] += 1;
                }
            }
        }

        cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
    }
}