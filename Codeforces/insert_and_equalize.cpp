#include <iostream>
#include <bits/stdc++.h>
#include <set>
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

int gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
} 
  
int findGCD(vector<ll> &a, int n) 
{ 
  int result = a[0]; 
  for (int i = 1; i < n; i++) 
  { 
    result = gcd(a[i], result); 
  
    if(result == 1) { 
        return 1; 
    } 
  } 
  return result; 
} 

int main() {
    setIO();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        set<ll> s;
        ll max_elem = -INF;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            max_elem = max(max_elem, a[i]);
            s.insert(a[i]);
        }

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        vector<ll> difs;
        for (int i = 1; i < n; i++) {
            difs.push_back(abs(a[i] - a[i - 1]));
        }

        ll x = findGCD(difs, n - 1);

        ll new_elem = max_elem;

        for (int i = 1; i < n; i++) {
            new_elem -= x;
            if (s.find(new_elem) == s.end()) break;
        }

        if (s.find(new_elem) != s.end()) {
            new_elem = max_elem + x;
            max_elem = new_elem;
        }

        a.push_back(new_elem);

        ll ans = 0;

        for (int i = 0; i < n + 1; i++) {
            ll d = abs(max_elem - a[i]);
            ans += d / x;
        }

        cout << ans << endl;
    }
}