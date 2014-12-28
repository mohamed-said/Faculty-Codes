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

class TheSquareDivTwo {
public: vector<string> solve(vector <string> board) {

	int size = sz(board);
	vector<int> checkers(size, 0);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 'C')
				checkers[i]++;
		}
	}

	vector<string> gdeed;

	string temp = "";
	for (int i = 0; i < size; i++)
		temp += '.';

	for (int i = 0; i < size; i++) {
		gdeed.pb(temp);
	}

	int cnt;
	for (int i = 0; i < size; i++) {
		cnt = size - 1;
		for (int j = size - 1; j >= size - checkers[i]; j--) {
			gdeed[cnt][i] = 'C';
			--cnt;
		}
	}

	return gdeed;
}
};

// {"...C", ".C.C", ".C.C", "CCCC" }

// . . . C
// . C . C
// . C . C
// C C C C

int main() {
	string arr[2] = {"CC", ".C"};
	vector<string> vec(arr, arr + sizeof(arr) / sizeof(*arr));

	TheSquareDivTwo d;
	vector<string> vec2 = d.solve(vec);

	for (int i = 0; i < sz(vec2); i++)
		cout << vec2[i] << endl;

	return 0;
}
