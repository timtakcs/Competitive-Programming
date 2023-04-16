#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
	    int n; cin >> n;
	    string u; cin >> u;
	    string v = "";
	    u += '$';
	    int cur = 1;
	    for (int i = 1; i <= n; i++) {
            if (u[i] != u[i - 1]) {
                v += u[i - 1];
                if (cur == 2) v += u[i - 1];
                cur = 1;
            } else {
                cur++;
            }
	    }
	    cout << v << endl;
	}
	return 0;
}
