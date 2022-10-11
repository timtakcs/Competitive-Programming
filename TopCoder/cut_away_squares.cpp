#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class CutAwaySquares {
public:
    long long countCuts(long long a, long long b) {
        long long count = 0;

        while (a != b) {
            if (a < b) b -= a;
            else a -= b;
            count++;           
        }

        return count;
    }
};

int main() {
    CutAwaySquares sq;
    cout << sq.countCuts(5, 10) << endl;
    return 0;
}