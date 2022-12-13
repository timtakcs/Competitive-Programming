/*
ID: your_id_here
TASK: barn1
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
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, ns, c; fin >> m >> ns >> c;
    vector<int> stalls(c);

    for (int i = 0; i < c; i++) {
        fin >> stalls[i];
    }

    vector<int> gaps;
    for (int i = 1; i < stalls.size(); i++) {
        gaps.push_back(stalls[i] - stalls[i - 1] + 1);
    }
    
    sort(gaps.begin(), gaps.end(), greater<int>());

    for (int i = 0; i < m; i++) {
        ns -= gaps[i];
    }

    fout << ns << endl;


}