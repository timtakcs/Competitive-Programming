#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <algorithm>
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

int inter(set<int> &s1, set<int> &s2) {
    for (int x: s1) {
        if (s2.count(x)) {
            return x;
        }
    }

    return -1;
}

int main() {
    setIO();

    string quote; cin >> quote;

    int n = quote.size();

    string alph = "abcdefghijklmnopqrstuvwxyz_,.?!():;";

    map<char, int> alphabet;

    for (int i = 0; i < alph.length(); i++) {
        alphabet[alph[i]] = i;
    }

    vector<set<int>> first_map(n);
    vector<set<int>> second_map(n);
    vector<int> final_map(n);
    
    string out = "";

    for (int i = 0; i < n; i++) {
        out += alph[i % alph.size()];
    }

    cout << flush << out << endl;
    string in; cin >> in;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (out[i] == in[j]) {
                first_map[i].insert(j);
            }
        }
    }

    map<char, int> cnt;

    for (int i = 0; i < n; i++) {
        char temp = out[i];
        out[i] = alph[(alphabet[out[i]] + cnt[out[i]]) % alph.size()];
        cnt[temp]++;
    }

    cout << flush << out << endl;
    in.clear(); cin >> in;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (out[i] == in[j]) {
                second_map[i].insert(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        final_map[i] = inter(first_map[i], second_map[i]);
    }

    vector<char> ans(n);

    for (int i = 0; i < n; i++) {
        ans[i] = quote[final_map[i]];
    }

    string ans_string = "";
    for (auto c: ans) {
        ans_string += c;
    }

    cout << flush << ans_string << endl;

}