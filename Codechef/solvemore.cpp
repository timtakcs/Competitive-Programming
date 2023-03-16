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

struct p {
    int time;
    int rest;
    int total;
};

bool comp(p &p1, p &p2) {
    if (p1.total == p2.total) {
        return p1.time > p2.time;
    } else {
        return p1.total < p2.total;
    }
}

int main() {
    setIO();

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        
        set<int> arr;
        map<int, int> freq;
        vector<p> probs;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            arr.insert(-a[i]);

            if (!freq.count(a[i])) freq[a[i]] = 1;
            else freq[a[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            p problem;
            problem.time = a[i];
            problem.rest = b[i];
            problem.total = a[i] + b[i];
            probs.push_back(problem);
        }

        sort(probs.begin(), probs.end(), comp);

        int c = 0;

        for (int i = 0; i < n; i++) {
            k -= probs[i].total;
            if (k < 0) {
                k += probs[i].total;
                if (arr.upper_bound(-k) != arr.end()) {
                    // cout << -(*arr.upper_bound(-k)) << "<----" << endl;
                    c++;
                }
                break;
            } else {
                c++;
                freq[probs[i].time]--; 
                if (freq[probs[i].time] == 0) {
                    arr.erase(-probs[i].time);
                }
            }
        }

        cout << c << endl;
    }
}