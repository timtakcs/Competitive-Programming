#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair

int main() {
    int n; cin >> n;
    vector<int> even;
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (i % 2) odd.push_back(i);
        else even.push_back(i);
    }

    for (int i = 0; i < even.size(); i++) {
        cout << even[i] << " ";
    }
    for (int i = 0; i < odd.size(); i++) {
        cout << odd[i] << " ";
    }
}