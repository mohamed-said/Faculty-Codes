#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <utility>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <memory>
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

struct phone {
	string name;
	int num;
};

const int size = 1000007;
list<phone> L[size];
list<phone>::iterator it, it2;

int hash(string x) {
	int ascii = 0;
	for (int i = 0; i < sz(x); i++)
		ascii += int(x[i]);

	ascii %= size;
	return ascii;

}

bool find(string name) {
	int x = hash(name);
	it = L[x % size].begin();
	it2 = L[x % size].end();
	while (it != it2) {
		if ((*it).name == name)
			return true;
		it++;
	}
	return false;
}

void insert(phone x) {
	L[x.num % size].push_back(x);
}

void del(string name) {
	int x = hash(name);
	it = L[x % size].begin();
	it2 = L[x % size].end();
	while (it != it2) {
		if ((*it).name == name) {
			L[x % size].erase(it);
			return;
		}
		it++;
	}
}

int main() {

	return 0;
}
