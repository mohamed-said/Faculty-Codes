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
#include <ctime>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

int main() {

	list<int> LinkedList_first, LinkedList_second;

	LinkedList_first.push_back(1);
	LinkedList_first.push_back(3);
	LinkedList_first.push_back(5);
	LinkedList_first.push_back(7);
	LinkedList_first.push_back(9);

	LinkedList_second.push_back(2);
	LinkedList_second.push_back(4);
	LinkedList_second.push_back(6);
	LinkedList_second.push_back(8);
	LinkedList_second.push_back(10);

	list<int>::iterator it1;
	list<int>::iterator it2;

	for (it1 = LinkedList_first.begin(), it2 = LinkedList_second.begin();
			it1 != LinkedList_first.end() || it2 != LinkedList_second;
			it1++, it2++) {

		if (*it1 > *it2) {

		}

	}

	return 0;
}
