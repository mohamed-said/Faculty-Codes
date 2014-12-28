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

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

int getIdx(vi x, int s) {
	int i;
	for (i = 0; i < sz(x); i++) {
		if (x[i] == s)
			break;
	}
	return i + 1;
}

int main() {
	int t;
	cin >> t;
	vi vec(t);
	for (int i = 0; i < t; i++) {
		cin >> vec[i];
	}

	for (int i = 1; i <= t; i++)
		cout << getIdx(vec, i) << " ";
	return 0;
}
