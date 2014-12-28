#include <iostream>
#include <string>

using namespace std;

#define sz(x) (int)x.size()

class InsideOut {
public:
	string unscramble(string line) {
		string x = "";
		for (int i = (sz(line) / 2) - 1; i >= 0; i--) {
			x += line[i];
		}
		for (int i = sz(line) - 1; i >= sz(line) / 2; i--) {
			x += line[i];
		}
		return x;
	}
};

