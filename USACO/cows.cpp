/*
ID: your_id_here
TASK: milk2
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
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int n; fin >> n;
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        int start, finish; fin >> start >> finish;
        t[i] = mp(start, finish);
    }

    sort(t.begin(), t.end());

    vector<pair<int, int>> intvals;

    int index = 0;
    intvals.push_back(t[0]);

    for (int i = 0; i < n; i++) {
        if (t[i].s > intvals[index].s) {
            if (t[i].f > intvals[index].s) {
                index++;
                intvals.push_back(t[i]);
            }
            else {
                intvals[index].s = t[i].s - intvals[index].f;
            }
        }  
    }

    int idle = 0;
    int cont = 0;

    for (int i = 0; i < intvals.size() - 1; i++) {
        idle = max(idle, intvals[i+1].f - intvals[i].s);
    }

    for ()

    fout << cont << " " << idle << endl;
}