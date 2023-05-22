#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>
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

    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll cash = 0;
    ll stocks = arr[0];

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            if (cash >= arr[i]) {
                int num_stocks = cash / arr[i];
                stocks += num_stocks * arr[i];
                cash = cash % arr[i];
            }
            stocks *= (double)arr[i + 1] / (double)arr[i];
        }
        else {
            cash += stocks;
            stocks = 0;
        }
    }

    cout << cash + stocks << endl;

}