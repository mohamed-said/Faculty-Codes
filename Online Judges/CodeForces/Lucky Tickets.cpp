#include <iostream>

using namespace std;

bool isEqual(int n, string num) {
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < (n / 2); i++) {
		sum1 += (num[i] - '0');
	}
	for (int i = (n / 2); i < (int)num.size(); i++) {
		sum2 += (num[i] - '0');
	}

	if (sum1 == sum2)
		return true;
	return false;
}

bool isLucky (string x) {
	bool is = true;
	for (int i = 0; i < (int)x.size(); i++) {
		if (x[i] == '4' || x[i] == '7') {
			continue;
		} else {
			is = false;
			break;
		}
	}
	return is;
}

int main() {
	int x;
	string y;
	cin >> x >> y;
	if (isEqual(x, y) && isLucky(y))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
