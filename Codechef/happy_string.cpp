#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string s) {
    vector<char> v = {'a', 'e', 'o', 'i', 'u'};

    for (int k = 0; k < s.length() - 2; k++) {
        if(count(v.begin(), v.end(), s[k]) && count(v.begin(), v.end(), s[k + 1]) && count(v.begin(), v.end(), s[k + 2])) {
            cout << "Happy" << endl;
            return;
        }
    }

    cout << "Sad" << endl;
}

int main() {
    int t;
    string s;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> s;
        solve(s);
    }
}