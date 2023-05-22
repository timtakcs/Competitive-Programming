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

bool bigger(vector<int> &p1, vector<int> &p2, int n) {
    for (int i = 0; i < n; i++) {
        // cout << p2[i] << " " << p1[i] << endl;
        if (p2[i] > p1[i]) return true;
        else if (p2[i] < p1[i]) return false;
    }
    return false;
}

vector<int> operation(vector<int> &a, int pivot_start, int pivot_end) {
    vector<int> prefix;
    vector<int> mid;
    vector<int> suffix;

    for (int i = 0; i < pivot_start; i++) {
        prefix.pb(a[i]);
    }

    for (int i = pivot_start; i <= pivot_end; i++) {
        mid.pb(a[i]);
    }

    for (int i = pivot_end + 1; i < a.size(); i++) {
        suffix.pb(a[i]);
    }

    reverse(mid.begin(), mid.end());

    vector<int> res;
    for (int i = 0; i < suffix.size(); i++) {
        res.pb(suffix[i]);
    }
    for (int i = 0; i < mid.size(); i++) {
        res.pb(mid[i]);
    }
    for (int i = 0; i < prefix.size(); i++) {
        res.pb(prefix[i]);
    }
    
    // cout << "res: ";
    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    return res;

}

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        int max_num = n;
        if (a[0] == n) max_num = n-1;

        int pivot = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == max_num) {
                pivot = i;
                break;
            }
        }

        vector<int> max_p(n, -1);

        int pivot_start = pivot;
        int pivot_end = pivot;

        while (pivot_start >= 0) {
            vector<int> temp = operation(a, pivot_start, pivot_end);
            if (bigger(max_p, temp, n)) {
                max_p = temp;
            }

            pivot_start--;
        }

        pivot_start = pivot;
        pivot_end = pivot;

        pivot_start--;
        pivot_end--;

        while (pivot_start >= 0) {
            vector<int> temp = operation(a, pivot_start, pivot_end);
            if (bigger(max_p, temp, n)) {
                max_p = temp;
            }

            pivot_start--;
        }

        for (int i = 0; i < n; i++) {
            cout << max_p[i] << " ";
        }
        cout << endl;

    }
}