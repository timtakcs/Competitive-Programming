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
    while (t--) {
        int n; cin >> n;

        if (n == 2) cout << "1 4\n3 2" << endl;
        else {
            vector<int> nums;

            int x = 1;
            while (x <= n * n) {
                nums.push_back(x);
                x += 2;
            }

            x = 2;
            while (x <= n * n) {
                nums.push_back(x);
                x += 2;
            }

            for (int i = 0; i < n * n; i++) {
                cout << nums[i] << " ";
                if ((i + 1) % n == 0) cout << endl;
            }
        }
    }
}