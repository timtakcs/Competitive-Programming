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
        char trump; cin >> trump;
        vector<string> cards(2*n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> cards[i];
        }

        map<char, vector<string>> suits;

        string s = "CDHS";
        string temp = "";
        for (auto c: s) {
            if (c == trump) continue;
            else temp += c;
        }
        temp += trump;
        s = temp;

        for (int i = 0; i < 2 * n; i++) {
            suits[cards[i][1]].push_back(cards[i]);
        }

        for (auto c: s) {
            sort(suits[c].begin(), suits[c].end(), greater<string>());
        }

        vector<string> ans;
        bool possible = true;
        int idx = 0;

        while (idx < 4) { 
            if (suits[s[idx]].size() == 0) {
                idx++;
            } else {
                string card1 = suits[s[idx]].back();
                suits[s[idx]].pop_back();
                
                if (suits[s[idx]].size() == 0) {
                    if (suits[trump].size() == 0) {
                        possible = false;
                        break;
                    } else {
                        ans.push_back(card1 + " " + suits[trump].back());
                        suits[trump].pop_back();
                        idx++;
                    }
                } else {
                    ans.push_back(card1 + " " + suits[s[idx]].back());
                    suits[s[idx]].pop_back();
                }

            }
        }

        if (!possible) cout << "IMPOSSIBLE" << endl;
        else {
            for (auto x: ans) {
                cout << x << endl;
            }
        }
    }
}