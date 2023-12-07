#include <iostream>
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define f first
#define s second
#define mp make_pair
#pragma GCC optimize "trapv"

struct sensor {
    int x;
    int y;
    int x_beacon;
    int y_beacon;
    int manhattan;
};

sensor make_sensor(string line) {
    sensor * sens = new sensor();

    int count = 0;

    int i = 0;
    string nums = "-0123456789";
    while (i < line.length()) {
        if (line[i] == 'x' || line[i] == 'y') {
            char id = line[i];
            i++; i++;
            string num = "";
            while (nums.find(line[i]) != std::string::npos) {
                num += line[i];
                i++;
            }

            if (id == 'x') {
                if (count) sens->x_beacon = stoi(num);
                else sens->x = stoi(num);
            }
            else {
                if (count) sens->y_beacon = stoi(num);
                else sens->y = stoi(num);
                count++;
            }

            num = "";
        }
        else i++;
    }

    int man = abs(sens->x - sens->x_beacon) + abs(sens->y - sens->y_beacon);
    sens->manhattan = man;

    return *sens;
}

int main() {
    ofstream fout (".out");
    ifstream fin ("elves.in");

    string line;
    vector<string> lines;
    while (getline(fin, line)) {
        lines.push_back(line);
    }

    vector<sensor> sensors;

    int max_x = 0;
    int min_x = 9999999;
    int max_manhattan = 0;

    for (auto l: lines) {
        sensor sens = make_sensor(l);
        sensors.push_back(sens);
        max_x = max(max_x, max(sens.x, sens.x_beacon));
        min_x = min(min_x, min(sens.x, sens.x_beacon));
        max_manhattan = max(max_manhattan, sens.manhattan);
    }
    
    int count = 0;

    int y = 2000000;
    for (int x = min_x - max_manhattan; x < max_x + max_manhattan; x++) {
        bool flag = true;
        for (auto &sens: sensors) {
            int man = abs(x - sens.x) + abs(y - sens.y);
            if (sens.x_beacon == x && sens.y_beacon == y) continue;
            if (man <= sens.manhattan) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    vector<long> pos_lines;
    vector<long> neg_lines;

    for (auto &sens: sensors) {
        int dist = sens.manhattan;
        neg_lines.push_back(sens.x + sens.y - dist);
        neg_lines.push_back(sens.x + sens.y + dist);
        pos_lines.push_back(sens.x - sens.y - dist);
        pos_lines.push_back(sens.x - sens.y + dist);
    }

    long pos;
    long neg;

    long a; long b;

    for (int i = 0; i < pos_lines.size(); i++) {
        for (int j = i + 1; j < pos_lines.size(); j++) {

            a = pos_lines[i];
            b = pos_lines[j];

            if (abs(a - b) == 2) {
                pos = min(a, b) + 1;
            }

            a = neg_lines[i];
            b = neg_lines[j];

            if (abs(a - b) == 2) {
                neg = min(a, b) + 1;
            }
        }
    }

    long xpos = (pos + neg) / 2;
    long ypos = (neg - pos) / 2;

    unsigned long long ans = (4000000 * xpos) + ypos;
    cout << ans << endl;
}