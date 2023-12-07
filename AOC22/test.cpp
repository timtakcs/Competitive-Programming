#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i < 4; i += 2) {
        for (int j = 1; j < 4; j += 2) {
            cout << "x " << i << " y " << j << endl; 
        }
    }
}