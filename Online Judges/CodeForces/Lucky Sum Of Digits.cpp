#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

#define sz(x) (long long)x.size()
#define getmax(a,b) ((a)>(b)?(a):(b))

int sumOfDigits(string x) {
	int resBlaban = 0;
	for (int i = 0; i < sz(x) ; ++i) {
		resBlaban += x[i] - '0';
	}
	return resBlaban;
}

string generateLucky(int x) {
	string res = "";
	int size = x;

	for (int i = 0; i < x / 7; ++i) {
		res += '7';
	}

	while (size--) {
		if (sumOfDigits(res) == x) {
			return res;
		} else if (sumOfDigits(res) > x) {
			for (int j = 0; j < sz(res); ++j) {
				if (res[j] == '7') {
					res[j] = '4';
					break;
				}
			}
		} else if (sumOfDigits(res) < x) {
			res = '4' + res;
		}
	}
	return "1";
}

int main() {
	int n;
	cin >> n;
	string x = generateLucky(n);
	(x == "1") ? cout << -1 : cout << x;
	return 0;
}
