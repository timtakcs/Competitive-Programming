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

int mod(int x, int d) {
    int ans = x % d;
    if (ans < 0) {
        ans = d + ans;
    }

    return ans;
}

void compute_freq(string s, map<char, int> &m) {
    for (auto c: s) {
        m[c]++;
    }
}

double multindco(string s, string t) {
    map<char, int> f1;
    map<char, int> f2;

    compute_freq(s, f1);
    compute_freq(t, f2);

    double n = s.size();
    double m = t.size();

    double freq_sum = 0;

    for (int i = 0; i < 26; i++) {
        freq_sum += (double)(f1['a' + i] * f2['a' + i]);
    } 

    return freq_sum / (n * m);
}

double indco(string s) {
    map<char, int> f;
    compute_freq(s, f);

    double denom = s.size() * (s.size() - 1);   
    double freq_sum = 0;
    
    for (int i = 0; i < 26; i++) {
        freq_sum += (double)(f['A' + i] * (f['A' + i] - 1));
    }

    return freq_sum / denom;
}

string decrypt_vigenere(string key, string text) {
    int idx = 0;
    string ans = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] < 'a' || text[i] > 'z') {
            continue;
        }

        int offset = key[idx] - 'a';

        char newchar = 'a' + mod(text[i] - 'a' - offset, 26);
        ans += newchar;
        idx = (idx + 1) % key.size();
    } 

    return ans;
} 

string vigenere(string key, string text) {
    int idx = 0;
    string ans = "";
    for (int i = 0; i < text.size(); i++) {
        if (text[i] < 'a' || text[i] > 'z') {
            continue;
        }

        int offset = key[idx] - 'a';

        char newchar = 'a' + (text[i] - 'a' + offset) % 26;
        ans += newchar;
        idx = (idx + 1) % key.size();
    } 

    return ans;
}

// hamlet
// to be, or not to be, that is the question.

int main() {
    setIO();

    cout << vigenere("found", "paymentdue") << endl;
    cout << "##########################################################" << endl;
    cout << indco("RCZBWBFHSLPSCPILHBGZJTGBIBJGLYIJIBFHCQQFZBYFP") << endl;
    cout << indco("KHQWGIZMGKPOYRKHUITDUXLXCWZOTWPAHFOHMGFEVUEJJ") << endl;
    cout << "##########################################################" << endl;

    vector<string> arr = {"iwseesetftuonhdptbunnybioeatneghictdnsevi", "qibfhroeqeickxmirbqlflgkrqkejbejpepldfjbk", "iesnnciiheptevaireittuevmhooottrtaaflnatg"};

    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            cout << i + 1 << " " << j + 1 << " " << multindco(arr[i], arr[j]) << endl;
        }
    }

    cout << "##########################################################" << endl;
    cout << decrypt_vigenere("condiment", "rsghzbmcxtdvfsqhnigqxrnbmpdnsqsmbtrku") << endl;
}