#include <iostream>
#include <bits/stdc++.h>
#include <stack>
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

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        while (s.size() && a[s.top()] >= a[i]) {
            s.pop();
        }

        if (!s.size()) ans.push_back(0); 
        else ans.push_back(s.top() + 1);

        s.push(i);
    }

    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}