#include <iostream>
#include<bits/stdc++.h>
#include <set>
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

    set<int> s;

    int n, k; cin >> n >> k;

    for (int i = 0; i < k; i++) {
        char c; cin >> c;

        if (c == 'F') {
            int x; cin >> x;
            if (s.find(x) == s.end()) {
                s.insert(x);
            }
        } else if (c == 'C') {
            int a, b; cin >> a >> b;
            int lower = distance(s.begin(), s.lower_bound(a + 1));
            int upper = distance(s.begin(), s.upper_bound(b - 1));

            cout << upper - lower << endl;
        }
    }
}