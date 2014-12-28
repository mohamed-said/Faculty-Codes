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

int main() {

	string s;
	cin >> s;

	bool isAllUp = true;
	for (int i = 1; i < sz(s); i++)
		if (islower(s[i])) {
			isAllUp = false;
			break;
		}
	if (sz(s) == 1 && islower(s[0])) {
		s[0] = toupper(s[0]);
	} else if (islower(s[0]) && isAllUp) {
		s[0] = toupper(s[0]);
		for (int i = 1; i < sz(s); i++)
			s[i] = tolower(s[i]);
	} else if (isupper(s[0]) && isAllUp) {
		for (int i = 0; i < sz(s); i++)
			s[i] = tolower(s[i]);
	}
	cout << s << endl;

	return 0;
}
