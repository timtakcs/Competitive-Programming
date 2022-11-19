/*
ID: your_id_here
TASK: beads
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
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int n; fin >> n;
    string neck; fin >> neck;
    neck += neck;

    int size = neck.size();

    vector<vector<int>> left(size + 1, vector<int> (2, 0));
    vector<vector<int>> right(size + 1, vector<int> (2, 0));

    for (int i = 1; i < size; i++) {
        if (neck[i-1] == 'r') {
            left[i][0] = left[i-1][0] + 1;
            left[i][1] = 0; 
        }
        else if (neck[i-1] == 'b') {
            left[i][1] = left[i-1][1] + 1;
            left[i][0] = 0; 
        }
        else {
            left[i][0] = left[i-1][0] + 1;
            left[i][1] = left[i-1][1] + 1;
        }
    } 

    for (int j = size - 1; j >= 0; j--) {
        if (neck[j] == 'r') {
            right[j][0] = right[j+1][0] + 1;
            right[j][1] = 0;
        }
        else if (neck[j] == 'b') {
            right[j][1] = right[j+1][1] + 1;
            right[j][0] = 0;
        }
        else {
            right[j][1] = right[j+1][1] + 1;
            right[j][0] = right[j+1][0] + 1;
        }
    }

    int mx = 0;

    for (int i = 0; i < size; i++) {
        mx = max(mx, max(left[i][0], left[i][1]) + max(right[i][1], right[i][0]));
    }

    if (mx > n) mx = n;

    fout << mx << endl;
}
