#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define sz(x) (int)x.size()
#define million 1000000

int sti(string x) {
	stringstream ss;
	int i;
	ss << x;
	ss >> i;
	return i;
}

int getMax(string x) {
	string first, second, third;
	int maximum = -1, size;
	int one, two, three;

	size = sz(x) - 1;
	for (int i = 0; i < sz(x) ; ++i) {
		--size;
		for (int j = 0; j < size; ++j) {
			one = i + 1;
			two = j + 1;
			three = one + two;
			first = x.substr(0, one);
			second = x.substr(i + 1, two);
			third = x.substr(three, 100);

			if (first[0] == '0') {
				if (sz(first) > 1)
					continue;
			}
			if (second[0] == '0') {
				if (sz(second) > 1)
					continue;
			}
			if (third[0] == '0') {
				if (sz(third) > 1)
					continue;
			}

			if (sti(first) > million || sti(second) > million
					|| sti(third) > million || sti(first) < 0 || sti(second) < 0
					|| sti(third) < 0 || sz(first) > 7 || sz(second) > 7
					|| sz(third) > 7)
				continue;
			else if ((sti(first) + sti(second) + sti(third)) > maximum) {
				maximum = (sti(first) + sti(second) + sti(third));
			}
		}
	}
	return maximum;
}

int main() {
	string x;
	cin >> x;
	cout << getMax(x);
	return 0;
}
