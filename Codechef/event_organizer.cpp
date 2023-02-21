#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

struct event {
    int start;
    int end;
    int cost;
};

int main() {
    setIO();

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        map<int, vector<event>> events;
        int max_end = 0;
        for (int i = 0; i < n; i++) {
            event e;
            cin >> e.start >> e.end >> e.cost;
            events[e.end].push_back(e);
            max_end = max(max_end, e.end);
        }

        vector<int> dp(max_end + 1, 0);

        dp[0] = 0;
        for (int i = 1; i <= max_end; i++) {
            dp[i] = dp[i - 1];
            for (auto e: events[i]) {
                dp[i] = max(e.cost + dp[e.start], dp[i]);
            }
        }

        cout << dp[max_end] << endl;
    }
}