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

    string s; cin >> s;
    int n = s.length();

    string best = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, j - i);
            string s3 = s.substr(j, n - j);

            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());
            reverse(s3.begin(), s3.end());

            string temp = s1 + s2 + s3;

            if (temp < best) {
                best = temp;
            }
        }
    }

    cout << best << endl;
}