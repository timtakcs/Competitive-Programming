/*
ID: your_id_here
TASK: milk
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
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int t; int n; fin >> t >> n;
    vector<pair<int, int>> m(n);
    for(int i = 0; i < n; i++) {
        int a, b; fin >> a >> b;
        m[i] = mp(a, b);
    }

    int price = 0;
    sort(m.begin(), m.end());
    int idx = 0;
    for (idx; idx < m.size() && t > 0; idx++) {
        t -= m[idx].s;
        price += m[idx].s * m[idx].f;
    }
    if (t < 0) {
        price -= abs(t) * m[idx-1].f;
    }

    fout << price << endl;
}