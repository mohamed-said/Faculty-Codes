#include <iostream>
#include <vector>
#include <string>
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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

int main() {

	string x;
	bool isF = false;
	setc s;

	s.ins('H');
	s.ins('Q');
	s.ins('9');

	cin >> x;

	for (int i = 0; i < sz(x) ; i++) {
		if (s.find(x[i]) != s.end()) {
			isF = true;
			break;
		}
	}
	(isF) ? cout << "YES" : cout << "NO";

	return 0;
}
