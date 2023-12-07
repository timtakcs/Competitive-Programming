#include <iostream>
#include <bits/stdc++.h>
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

    string s1, s2; cin >> s1 >> s2;
    if ((s1 == "OCT" && s2 == "31") || (s1 == "DEC" && s2 == "25")) cout << "yup" << endl;
    else cout << "nope" << endl;    
}