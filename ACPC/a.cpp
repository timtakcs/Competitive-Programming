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
    string line;
    int c = 0;
    while (getline(cin, line)) {
        string rev = line;
        reverse(rev.begin(), rev.end());
        if (rev == line) c++;
    }
    cout << c << endl;
}