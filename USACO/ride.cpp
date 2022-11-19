/*
ID: your_id_here
TASK: ride
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
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s1, s2;
    fin >> s1;
    fin >> s2;

    int sum1 = 1;
    for (int i = 0; i < s1.size(); i++) {
        int x = s1[i] - '0';
        x -= 16;
        sum1 *= x;
    } 
    int sum2 = 1;
    for (int i = 0; i < s2.size(); i++) {
        int x = s2[i] - '0';
        x -= 16;
        sum2 *= x;
    } 

    if (sum1 % 47 == sum2 % 47) fout << "GO" << endl;
    else fout << "STAY" << endl;

}