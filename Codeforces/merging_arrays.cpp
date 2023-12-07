#include <iostream>
#include <bits/stdc++.h>
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

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        map<int, int> seqa;
        map<int, int> seqb;

        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) cur++;
            else {
                seqa[a[i - 1]] = max(seqa[a[i - 1]], cur);
                cur = 1;
            }
        }  

        seqa[a[n - 1]] = max(seqa[a[n - 1]], cur);

        cur = 1;

        for (int i = 1; i < n; i++) {
            if (b[i] == b[i - 1]) cur++;
            else {
                seqb[b[i - 1]] = max(seqb[b[i - 1]], cur);
                cur = 1;
            }
        }  

        seqb[b[n - 1]] = max(seqb[b[n - 1]], cur);
        
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, seqa[a[i]] + seqb[a[i]]);
        }

        for (int i = 0; i < n; i++) {
            ans = max(ans, seqa[b[i]] + seqb[b[i]]);
        }

        cout << ans << endl;
    }
}