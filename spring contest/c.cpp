#include <iostream>
#include <string>
#include <vector>

using std::cin, std::vector, std::cout, std::endl;

struct range {
    int l, r;
    range(int l, int r) : l(l), r(r) {}

    bool contains(int x) const {
        return l <= x && x <= r;
    }
};

vector<range> getListOfValidRangesFor(vector<range> ranges, int x) {
    vector<range> validRanges;
    for (auto r : ranges) {
        if (r.contains(x)) {
            validRanges.push_back(r);
        }
    }
    return validRanges;
}

int main() {
    int S, G;
    cin >> S >> G;

    vector<range> ranges;

    std::string name;
    int l, r;
    for (int i = 0; i < G; ++i) {
        cin >> name >> l >> r;
        ranges.emplace_back(l, r);
    }

    int steps = 0;
    vector<range> currRanges = ranges;
    for (int i = 0; i < S; ++i) {
        int x;
        cin >> x;

        auto validRanges = getListOfValidRangesFor(currRanges, x);
        if (validRanges.empty()) {
            steps++;
            currRanges = getListOfValidRangesFor(ranges, x);
        } else {
            currRanges = validRanges;
        }
    }

    cout << steps << endl;
}