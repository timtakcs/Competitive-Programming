#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <map>
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

void print_vector(vector<int> &a) {
    for (auto x: a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n); 
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        vector<int> right(k, -1);
        vector<int> left(k, -1);

        int count = 1;

        for (int i = 0; i < n; i++) {
            while (count <= a[i]) {
                left[count - 1] = i;
                count++;
            }
        }

        count = 1;
        for (int i = n - 1; i >= 0; i--) {
            while (count <= a[i]) {
                right[count - 1] = i;
                count++;
            }
        }

        for (int i = 0; i < k; i++) {
            if (cnt[i + 1] != 0) cout << 2 * (right[i] - left[i] + 1) << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}