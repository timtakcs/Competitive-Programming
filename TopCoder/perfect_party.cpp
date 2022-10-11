#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

class PerfectParty {
public:
    long invite(vector<int> candies) {
        int len = candies.size();
        int total = pow(2.0, (double)len);

        long total_ways = 0;

        int num = 0;
        while (num < total) {

            int count = 0;
            int count_people = 1;

            for (int i = 0; i < (int)len; i++) {
                if ((1 << i) & num) {
                    count += candies[i];
                    count_people++;
                }
            }

            if ((count % count_people) == 0) total_ways++;
            num++;
        }
        return total_ways;
    }
};

int main() {
    vector<int> candies = {1, 1, 1, 1, 1, 1, 1, 1}; 
    PerfectParty party;
    cout << party.invite(candies) << endl;
    return 0;
}