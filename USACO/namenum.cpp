/*
ID: your_id_here
TASK: namenum
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
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");

    bool found = false;
    string num; fin >> num;
    string name;
    while (dict >> name) {
        if (name.size() == num.size()) {
            string id = "";
            for (int i = 0; i < name.size(); i++) {
                if (name[i] == 'Q' || name[i] == 'Z') continue;
                if (name[i] < 'Q') id += (name[i] - 'A')/3 + '2';
                else id += (name[i] - 'Q')/3 + '7';
            }
            if (id == num) {
                fout << name << endl;
                found = true;
            }
        }
    }
    if (!found) fout << "NONE" << endl;
}