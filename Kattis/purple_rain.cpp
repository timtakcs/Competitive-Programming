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

    vector<int> dif(n);

    if (s[0] == 'R') dif[0] = -1;
    else dif[0] = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'R') dif[i] = dif[i-1] - 1;
        else dif[i] = dif[i-1] + 1;
    }

    int min_val = 0;
    int min_index = -1;
    int max_val = 0;
    int max_index = -1;

    for (int i = 0; i < n; i++) {
        if (dif[i] < min_val) {
            min_val = dif[i];
            min_index = i;
        }
        if (dif[i] > max_val) {
            max_val = dif[i];
            max_index = i;
        }
    }

    if (min_index < max_index) {
        cout << min_index + 2 << " " << max_index + 1 << endl;
    } else {
        cout << max_index + 2 << " " << min_index + 1 << endl;
    }

}