#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define sz(x) (int)x.size()
bool is_dangerous(string x) {
	int ctr = 1;
	for (int i = 0; i < sz(x) - 1; i++) {
		if (x[i] == x[i + 1])
			ctr++;
		else
			ctr = 1;
		if (ctr >= 7)
			return true;
	}
	return false;
}

int main() {
	string x;
	cin >> x;
	if (is_dangerous(x))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
