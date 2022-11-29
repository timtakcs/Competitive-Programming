/*
ID: your_id_here
TASK: transform
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

void transform(vector<vector<char>> &img, int n) {
    for (int i = 0; i < n/2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            char temp = img[i][j];
            img[i][j] = img[n - 1 - j][i];
            img[n - 1 - j][i] = img[n - 1 - i][n - j - 1];
            img[n - 1 - i][n - j - 1] = img[j][n - 1 - i];
            img[j][n - i - 1] = temp;
        }
    }
}

void reflect(vector<vector<char>> &img, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
            char temp = img[i][n - 1 - j];
            img[i][n - 1 - j] = img[i][j];
            img[i][j] = temp;
        }
    }
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    int n; fin >> n;
    vector<vector<char>> og(n, vector<char>(n));
    vector<vector<char>> nog(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        string r; fin >> r;
        for (int j = 0; j < n; j++) {
            og[i][j] = r[j];
        }
    }
    for (int i = 0; i < n; i++) {
        string r; fin >> r;
        for (int j = 0; j < n; j++) {
            nog[i][j] = r[j];
        }
    }

    int index = 7;

    bool flag = false;

    vector<vector<char>> temp = og;
    for (int i = 1; i < 4; i++) {
        transform(temp, n);
        if (temp == nog) {
            index = i;
            flag = true;
            break;
        }
    }
    if (!flag) {
        temp = og;
        reflect(temp, n);
        for (int i = 0; i < 4; i++) {
            if (!i && (temp == nog)) {
                index = 4;
                break;
            }
            else {
                transform(temp, n);
                if (temp == nog) {
                    index = 5;
                    break;
                }
            }
        }
    }

    if (og == nog) index = min(6, index);

    fout << index << endl; 
}