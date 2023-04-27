#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#pragma GCC optimize "trapv"

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
}

void swap(vector<int> &arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    setIO();

    vector<string> room(10);
    for (int i = 0; i < 10; i++) {
        cin >> room[i];
    }

    // left

    set<char> vis;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (room[i][j] >= 'A' && room[i][j] <= 'Z') {
                vis.insert(room[i][j]);
                break;
            }
            else if (room[i][j] == '#') {
                break;
            }
        }
    }

    // right
    
    for (int i = 0; i < 10; i++) {
        for (int j = 9; j >= 0; j--) {
            if (room[i][j] >= 'A' && room[i][j] <= 'Z') {
                vis.insert(room[i][j]);
                break;
            }
            else if (room[i][j] == '#') {
                break;
            }
        }
    }

    // top

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (room[j][i] >= 'A' && room[j][i] <= 'Z') {
                vis.insert(room[j][i]);
                break;
            }
            else if (room[j][i] == '#') {
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 9; j >= 0; j--) {
            if (room[j][i] >= 'A' && room[j][i] <= 'Z') {
                vis.insert(room[j][i]);
                break;
            }
            else if (room[j][i] == '#') {
                break;
            }
        }
    }

    cout << vis.size() << endl;
}