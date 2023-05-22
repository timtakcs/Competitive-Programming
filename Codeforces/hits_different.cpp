#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    setIO();

    int t; cin >> t;

    vector<vector<int>> stack(2024, vector<int>(2024));

    int x = 0;
    int y = 0;

    int count = 1;

    for (int i = 0; i < 64; i++) {
        y = i;
        x = 0;
        while (y >= 0) {
            stack[y][x] = count * count;
            count++;
            y--; x++;
        }
    }

    while(t--) {
        int n; cin >> n;

        
    }
}