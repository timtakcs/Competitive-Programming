/*
ID: your_id_here
TASK: dualpal
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

string convert(int n, int base) {
    string nums = "0123456789ABCDEFGHIJKLMNOP";
    string new_num = "";
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, sum; fin >> n >> sum;

    int nums = 0;

    while (nums < n) {
        sum++;
        int count = 0;
        for (int b = 2; b < 11; b++) {
            string conv = convert(sum, b);
            string rev = conv;
            reverse(rev.begin(), rev.end());
            if (rev == conv) count++;
            if (count >= 2) {
                fout << sum << endl;
                nums++;
                break;
            }
        }
    }
}