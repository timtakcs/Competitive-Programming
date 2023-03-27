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
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        map<char, int> a;
        map<char, int> b;
        
        a[s[0]] = 1;
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (!b.count(s[i])) {
                b[s[i]] = 1;
                cur++;
            } else {
                b[s[i]]++;
            }
        }

        int ans = cur;

        // cout << ans <<"dfads"<< endl;

        for (int i = 1; i < n; i++) {
            if (!a.count(s[i]) && b[s[i]] > 1) {
                cur++;
            } else if (a.count(s[i]) && b[s[i]] <= 1) {
                cur--;
            }

            if (!a.count(s[i])) a[s[i]] = 1;
            else a[s[i]]++;
            
            b[s[i]]--;
            ans = max(cur, ans);
        }

        cout << ans << endl;
    }
}