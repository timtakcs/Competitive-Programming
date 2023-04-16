#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
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

int best = INF;

int solve(vector<int> &arr, int k, int last, int n, int score) {
    if (k == n) {
        best = min(score + arr[k], best);
        return best;
    }
    if (k > n || k < 1) return INF;

    return min(solve(arr, k + last + 1, last + 1, n, score + arr[k]),
               solve(arr, k - last, last, n, score + arr[k]));
}

int main() {
    setIO();

    int n; cin >> n;
    vector<int> arr(2000);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i + 1];
    }

    cout << solve(arr, 2, 1, n, 0) << endl;
}