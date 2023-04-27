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

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    // int n; cin >> n;
    // int sum = (n * (n + 1)) / 2;
    // if (sum % 2 == 1) {
    //     cout << 1 << endl;
    // } else {
    //     cout << 0 << endl;
    // }

    int h, w; cin >> h >> w;

    int tag1 = 0;
    int tag2 = 0;

    vector<string> s1;
    vector<string> s2;

    map<int, int> c1;
    map<int, int> c2;


    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        s1.push_back(s);
    }

    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        s2.push_back(s);
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (s1[j][i] == '#') continue;
        }
    }

    // if (tag1 == tag2 || dot1 == dot2) cout << "Yes" << endl;
    // else cout << "No" << endl;
}