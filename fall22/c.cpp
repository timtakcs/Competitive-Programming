#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"
#include <math.h>
#define pi 3.1415926535

int main() {
    int n; int k; double r;
    cin >> n >> k >> r;
    vector<double> angles(n);

    for (int i = 0; i < n; i++) {
        cin >> angles[i];
        angles[i] = (double)angles[i];
    }

    double prev = angles[0];
    double total = 180.0 + prev;

    angles.push_back(total);

    vector<double> slices;
    for (int a = 1; a <= n; a++) {
        double ratio = (angles[a] - angles[a - 1])/360.0;
        slices.push_back(ratio * pi * (r * r));
    }

    for (int i = 0; i < n; i++) {
        slices.push_back(slices[i]);
    }

    vector<double> prefix(2 * n);
    prefix[0] = slices[0];

    for (int i = 1; i < slices.size(); i++) {
        prefix[i] = prefix[i - 1] + slices[i];
    }

    int left = 0;
    int right = k;
    double mx = 0;

    if (k != 2 * n) {
        while (right < slices.size()) {
            double sum = 0.0;
            sum = prefix[right] - prefix[left];
            mx = max(mx, sum);
            right++; left++;
        }
    }
    else mx = pi * (r * r);

    cout << setprecision(15) << mx << endl;
}

// 3 6 10.0
// 0.0 90.0 135.0
