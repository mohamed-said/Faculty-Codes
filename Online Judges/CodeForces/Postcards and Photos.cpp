#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define sz(x) (int)x.size()

int main() {
	int ctr = 0, runner = 1;
	string x;
	cin >> x;
	for (int i = 0; i < sz(x) - 1; i++) {
		if (x[i] != x[i + 1]) {
			if (runner >= 5) {
				ctr += (runner / 5);
				if (runner % 5 > 0)
					ctr++;
			} else {
				ctr++;
			}
			runner = 1;
		} else if (runner == 5) {
			runner = 1;
			ctr++;
		} else
			runner++;
	}
	if (runner >= 1)
		ctr++;

	cout << ctr;

	return 0;
}
