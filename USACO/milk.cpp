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

    int total = 0;
    int price = 0;
    sort(m.begin(), m.end());
    int idx = 0;
    if(t) {
        while (total <= t) {
            if (total + m[idx].s <= t) {
                price += m[idx].f * m[idx].s;
                total += m[idx].s;
                idx++;
            }
            else {
                int dif = total + m[idx].s - t;
                price += m[idx].f * dif;
                break;
            }
        }
    }

    fout << price << endl;
}