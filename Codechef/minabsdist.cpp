#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

pair<int, int> get_dist(char x, char y) {
    int a = x - 'a';
    int b = y - 'a';
    
    int ab, ba;

    if (a < b) {
        ab = b - a;
        ba = 26 - ab;
    } else {
        ab = 26 - a + b;
        ba = a - b;
    }

    return mp(ab, ba);
}

int main() {
    setIO();

    int t;
	int n;
	cin >> t;
	while (t--) {
	    cin >> n;
	    string s1, s2; cin >> s1 >> s2;
	    
	    int dist = 0;

        for (int i = 0; i < n; i++) {
            pair<int, int> d = get_dist(s1[i], s2[i]);
            int ab = d.f;
            int ba = d.s;

            if (dist + ab <= abs(dist - ba)) {
                dist += ab;
            } else {
                dist -= ba;
            }
        }

        cout << abs(dist) << endl;
    }
}