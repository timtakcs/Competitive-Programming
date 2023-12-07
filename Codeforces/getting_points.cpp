#include <iostream>
#include <bits/stdc++.h>
#define ll unsigned long long
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

    int T; cin >> T;
    while (T--) {
        ll n, l, t, p; cin >> n >> p >> l >> t;


        ll nt = (n - 1) / 7 + 1;
        
        ll ndt = nt / 2;
        ll prod_days = ndt * (2 * t + l);

        if (prod_days > p) {
            ndt -= (prod_days - p) / (2 * t + l);
        } else if (prod_days < p) {
            if (nt % 2 == 1) {
                prod_days += t + l; 
                ndt++; 
            } 

            if (prod_days < p) {
                ll additional_points_needed = p - prod_days;
                ll additional_days = (additional_points_needed + l - 1) / l;
                ndt += additional_days;
            }
        }

        cout << n - ndt << endl;

    }
}

/*
1
22 12 1 1
*/