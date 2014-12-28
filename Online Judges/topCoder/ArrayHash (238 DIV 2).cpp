#include <vector>
#include <string>
#include <iostream>
#define sz(x) (int)x.size()
using namespace std;
class ArrayHash {
public:
	int getHash(vector<string> input) {
		int hash = 0;
		for (int i = 0; i < sz(input) ; i++) {
			for (int j = 0; j < sz(input[i]) ; j++) {
				hash += (input[i][j] - 'A') + i + j;
			}
		}
		return hash;
	}
};
