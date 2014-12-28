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

void valid(int);

double b_s(double s, double e) {
	for (double size = (e - s) / 2; size > 1e-9; size *= .5)
		if (valid(s + size))
			s += size;
	return s;
}

//Searching for the last True in TTTTTTTTTTTTTTFFFFFFFFFFFFF pattern
//change val to !val to search for last False in FFFFFFFFFTTTTTTTTT
//pattern

int b_s(int s, int e) {
	while (s < e) {
		int mid = s + (e - s + 1) / 2;
		if (valid(mid))
			s = mid;
		else
			e = mid - 1;
	}
	return s;
}

//Searching for the first True in FFFFFFFFTTTTTTTTT pattern
//change val to !val to search for the first False in TTTTTTTTTFFFFFFF
//pattern
int bs(int s, int e) {
	while (s < e) {
		int mid = (s + (e - s) / 2);
		if (valid(mid))
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}
