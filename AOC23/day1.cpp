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

int part1(string s) {
    int l = 0;
    int r = s.length() - 1;

    while (s[l] > '9' || s[l] < '0') {
        l++;
    }

    while (s[r] > '9' || s[r] < '0') {
        r--;
    }

    string ans = "";
    ans += s[l];
    ans += s[r];

    return stoi(ans);

}

int part2(string s, map<string, int> &nums) {
    size_t first = string::npos;
    size_t last = 0;

    bool found_last = false;

    string first_rep = "";
    string last_rep = "";

    for (auto &num : nums) {
        size_t pos = s.find(num.first);
        if (pos < first) {
            first_rep = num.first;
            first = pos;
        }
    }
    
    for (auto &num : nums) {
        size_t pos = s.rfind(num.first);
        if (pos < s.length() && pos >= last) {
            found_last = true;
            last_rep = num.first;
            last = pos;
        }
    }

    int l = 0;
    int r = s.length() - 1;

    while ((s[l] > '9' || s[l] < '0') && l < s.length()) l++;
    while ((s[r] > '9' || s[r] < '0') && r >= 0) r--;

    string ans = "";
    if (l < first) {
        ans += s[l];
    } else {
        ans += to_string(nums[first_rep]);
    }

    if (r == -1) r++;

    if (r > last || !found_last) {
        ans += s[r];
    } else {
        ans += to_string(nums[last_rep]);
    }

    // cout << ans << endl;

    return stoi(ans);
}

int main() {
    setIO();

    freopen("AOC23/input.txt", "r", stdin);
    freopen("AOC23/output.txt", "w", stdout);

    map<string, int> nums;

    nums["one"] = 1;
    nums["two"] = 2;
    nums["three"] = 3;
    nums["four"] = 4;
    nums["five"] = 5;
    nums["six"] = 6;
    nums["seven"] = 7;
    nums["eight"] = 8;
    nums["nine"] = 9;

    string s;

    int sum = 0;

    while (!cin.eof()) {
        cin >> s;

        sum += part2(s, nums);
    }

    cout << sum;
}