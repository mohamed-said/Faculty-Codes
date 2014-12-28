#include <iostream>
#include <vector>
#include <string>

#define sz(x) (int)x.size()
#define getmax(a,b) ((a)>(b)?(a):(b))

using namespace std;

// lucky conversion
int main() {
	int four = 0, seven = 0;
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < sz(x) ; ++i) {
		if (x[i] == '4' && y[i] == '7')
			four++;
		else if (x[i] == '7' && y[i] == '4')
			seven++;
	}

	cout << getmax(four, seven);
	return 0;
}
