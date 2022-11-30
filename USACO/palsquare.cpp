/*
ID: your_id_here
TASK: palsquare
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

string convert(string num, int base) {
    string nums = "0123456789ABCDEFGHIJKLMNOP";
    string new_num = "";
    int n = stoi(num);
    while (n) {
        int x = n % base;
        new_num += nums[x];
        n -= x;
        n /= base;
    }
    reverse(new_num.begin(), new_num.end());
    return new_num;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    cout << convert("264", 10);

    int base; fin >> base;
    for (int i = 1; i < 300; i++) {
        int square = i * i;
        string conv = convert(to_string(square), base);
        string copy = conv;
        reverse(copy.begin(), copy.end());
        if (copy == conv) {
            fout << convert(to_string(i), base) << " " << conv << endl; 
        }
    }
}