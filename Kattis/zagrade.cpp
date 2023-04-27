#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define mt make_tuple
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

    string s; cin >> s;

    stack<pii> process;
    vector<pii> pairs;
    set<string> used;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            pii temp = mp(i, -1);
            process.push(temp);
        } else if (s[i] == ')') {
            pii temp = process.top(); process.pop();
            temp.s = i;
            pairs.pb(temp);
        }
    }

    // strip s of all parentheses
    string stripped = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '(' && s[i] != ')') {
            stripped += s[i];
        }
        else {
            stripped += ' ';
        }
    }

    vector<string> valid;

    for (int i = 1; i < 1 << pairs.size(); i++) {
        string temp = stripped;
        for (int j = 0; j < pairs.size(); j++) {
            if (!(i & (1 << j))) {
                temp[pairs[j].f] = '(';
                temp[pairs[j].s] = ')';
            }
        }

        // strip temp of white space
        string temp2 = "";
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] != ' ') {
                temp2 += temp[j];
            }
        }

        if (!used.count(temp2)) {
            used.insert(temp2);
            valid.pb(temp2);
        }
    }

    sort(valid.begin(), valid.end());

    for (int i = 0; i < valid.size(); i++) {
        cout << valid[i] << endl;
    }
}