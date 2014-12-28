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

struct S {
	int first, second;
};


void _swap (int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

void _swap2 (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

S _swap3 (int x, int y) {

	S p;
	p.first = y;
	p.second = x;
	return p;
}

void _swap4 (int* &x, int* &y) {
	int* temp = x;
	x = y;
	y = temp;
}


int main() {
	int x = 5, y = 6;
	cout << x << " " << y << endl;

	_swap(x, y);
	cout << x << " " << y << endl;

	int *ptr, *ptr2;
	ptr = &x;
	ptr2 = &y;
	_swap2(ptr, ptr2);
	cout << x << " " << y << endl;

	S p = _swap3(x, y);
	cout << p.first << " " << p.second << endl;

	int *p1, *p2;
	p1 = &x;
	p2 = &y;
	_swap4(p1, p2);
	cout << x << " " << y << endl;

	return 0;
}
