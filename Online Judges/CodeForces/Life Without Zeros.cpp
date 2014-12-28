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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

string removeZero(string x) {
	int size = sz(x);
	for (int i = 0; i < size; i++) {
		if (x[i] == '0') {
			x.erase(i, 1);
			++size;
			--i;
		}
	}
	return x;
}

ll strToInt(string x) {
	stringstream ss;
	ll temp;
	ss << x;
	ss >> temp;
	return temp;
}

string intToStr(ll x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	return s;
}

int main() {

	ll x, y, z;
	cin >> x >> y;
	z = x + y;
	string a, b, c;

	a = intToStr(x);
	b = intToStr(y);
	c = intToStr(z);

	a = removeZero(a);
	b = removeZero(b);
	c = removeZero(c);

	((strToInt(a) + strToInt(b)) == strToInt(c)) ? cout << "YES"
			: cout << "NO";

	return 0;
}
