#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define sz(x) (int)x.size()

class LetterStrings {
public:
	int sum(vector<string> s) {
		int sum = 0;
		for (int i = 0; i < sz(s) ; i++) {
			for (int j = 0; j < sz(s[i]) ; j++) {
				if (isalpha(s[i][j]))
					sum++;
			}
		}
		return sum;
	}
};
