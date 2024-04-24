#include <iostream>
#include <bits/stdc++.h>
#include <queue>
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<ll> a;
        priority_queue<ll> b;

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            sum += x;
            a.push(x);
        }   

        b.push(sum);

        while(a.size() && b.size() && b.top() >= a.top()) {

            // cout << a.top() << " " << b.top() << endl;

            if (a.top() != b.top()) {
                ll temp = b.top(); b.pop();

                b.push(temp / 2);
                b.push((temp + 1) / 2);
            } else {
                a.pop(); b.pop();
            }
        }

        if (a.size() == 0 && b.size() == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
 
    }
}