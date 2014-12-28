#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>
#include <iomanip>
#include <memory>
#include <map>
#include <exception>
#include <stdexcept>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
using namespace __gnu_cxx;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

class CCipher {
public:
	string decode(string cipherText, int shift) {

		for (int i = 0; i < sz(cipherText) ; i++) {
			int orig = (int) cipherText[i] - shift;
			if (orig < 65) {
				cipherText[i] = char(orig + 26);
			} else {
				cipherText[i] = char(orig);
			}
		}
		return cipherText;
	}
};

int main() {
	CCipher d;
	cout << d.decode("VQREQFGT", 2);
	return 0;
}
