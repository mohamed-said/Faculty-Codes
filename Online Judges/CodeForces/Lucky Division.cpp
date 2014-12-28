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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
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

bool isLucky(int x) {
	while (x > 0) {
		if (x % 10 == 4 || x % 10 == 7)
			x /= 10;
		else
			return false;
	}
	return true;
}

int main() {
	int x;
	scanf("%d", &x);
	if(isLucky(x))
		cout << "YES";
	else {
		if (x % 4 == 0 || x % 7 == 0 || x % 47 == 0 || x % 74 == 0 || x % 447 == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
