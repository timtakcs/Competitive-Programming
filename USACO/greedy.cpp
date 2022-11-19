/*
ID: your_id_here
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    map<string, int> cash;
    vector<string> names;
    int n; fin >> n;

    for (int i = 0; i < n; i++) {
        string p;
        fin >> p; 
        cash[p] = 0;
        names.push_back(p);
    }

    for (int i = 0; i < n; i++) {
        string g; fin >> g;
        int m; int k; fin >> m >> k;
        int left = (m && k) ? m % k : 0;
        int give = (m && k) ? m / k : 0;

        for (int j = 0; j < k; j++) {
            string r; fin >> r;
            cash[r] += give;
        }
        cash[g] -= m - left;
    }

    for (auto &n : names) {
        fout << n << " " << cash[n] << endl;
    }

}