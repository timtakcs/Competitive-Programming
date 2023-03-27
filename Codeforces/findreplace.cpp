#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> pos;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!pos.count(s[i])) pos[s[i]] = i;
            else {
                if ((i - pos[s[i]]) % 2 == 1) {
                    // cout << s[i] << " " << i << " " << pos[s[i]] << "<-" <<endl;
                    cout << "NO" << endl;
                    flag = false;
                    break;
                } else {
                    pos[s[i]] = i;
                }
            }
        }
        if (flag) cout << "YES" << endl;
    } 
}