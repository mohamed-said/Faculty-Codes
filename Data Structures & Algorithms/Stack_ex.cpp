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

bool check(string x) {
	bool balanced = true;
	vector<pair<char, int> > MF(8);
	MF[0].first = '{'; 	MF[0].second = 0;
	MF[1].first = '}';	MF[1].second = 1;
	MF[2].first = '[';	MF[2].second = 2;
	MF[3].first = ']';	MF[3].second = 3;
	MF[4].first = '<';	MF[4].second = 4;
	MF[5].first = '>';	MF[5].second = 5;
	MF[6].first = '(';	MF[6].second = 6;
	MF[7].first = ')';	MF[7].second = 7;

	if (sz(x) % 2 == 1)
		return false;

	for (int i = 0; i < sz(x) / 2; i++) { //{}[]
		for (int search = 0; search < sz(MF); i++) {
			if (MF[search].first == x[i]) {

			}
		}
	}

	return balanced;
}

int main() {
	string x;
	cin >> x;

	for (int i = 0; i < sz(x) / 2; i++) {
		cout << x[i] << x[sz(x) - i - 1];
	}

//	if(check(x))
//		cout << "Balanced" << endl;
//	else
//		cout << "Not Balanced" << endl;
	return 0;
}


/*
*
* 	MF[0].second = '1';
	MF[1].second = '2';
	MF[2].second = '3';
	MF[3].second = '4';
	MF[4].second = '5';
	MF[5].second = '6';
	MF[6].second = '7';
	MF[7].second = '8';
*
*/
