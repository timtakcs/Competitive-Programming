#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

int main() {
    setIO();

    double l; cin >> l;
    int k; cin >> k;

    cout << setprecision(15) << fixed << (l / pow(sqrt(2), k)) * (l / pow(sqrt(2), k)) << endl;
}