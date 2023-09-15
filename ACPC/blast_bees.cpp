#include <iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define pii pair<int, int>

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

    float d;
    int n;

    while(cin >> d && cin >> n && !(d == 0 && n == 0)) {
        vector<float> a(n);
        vector<float> b(n);
        vector<bool> m(n);

        for (int i = 0; i < n; i++) {
            float x, y; cin >> x >> y;

            a[i] = x;
            b[i] = y;
            m[i] = false;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if ((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]) <= (d * d)) {
                    m[i] = true;
                    m[j] = true;
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!m[i]) cnt++;
        }

        cout << n - cnt << " sour, " << cnt << " sweet" << endl;
    }
}