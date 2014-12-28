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

template<typename ValueType>
class Set;
template<typename ValueType>
ostream& operator<<(ostream & out, Set<ValueType> & setObj);

template <typename ValueType>
class Set {
	vector<ValueType> SET;
public:
	int size() {
		return sz(SET) ;
	}

	bool isEmpty() {
		if (SET.empty())
			return true;
		return false;
	}

	void insert(ValueType value) {
		bool Exist = false;

		for (int i = 0; i < sz(SET) ; i++) {
			if (SET[i] == value) {
				Exist = true;
				break;
			}
		}

		if (!Exist) {
			SET.pb(value);
			sort(all(SET));
		}
	}

	void remove(ValueType value) {
		int i;
		bool found = false;
		for (i = 0; i < sz(SET) ; i++) {
			if (SET[i] == value) {
				found = true;
				break;
			}
		}

		if (found)
			SET.erase(SET.begin() + i);
	}

	bool contains(ValueType value) {
		bool contains = false;
		for (int i = 0; i < sz(SET) ; i++) {
			if (SET[i] == value) {
				contains = true;
				break;
			}
		}
		return contains;
	}

//	bool isSubsetOf(const Set & set2) {
//
//	}

	void clear() {
		SET.clear();
	}

	bool operator==(Set & set2) {
		bool equals = true;

		for (int i = 0; i < sz(SET) ; i++) {
			if (SET[i] != set2.SET[i]) {
				equals = false;
				break;
			}
		}
		return equals;
	}

	bool operator!=(Set & set2) {
		bool notEqual = false;
		for (int i = 0; i < sz(SET) ; i++) {
			if (SET[i] != set2.SET[i]) {
				notEqual = true;
				break;
			}
		}
		return notEqual;
	}

	Set operator+(Set & set2) {
		Set newSet;
		for (int i = 0; i < sz(SET) ; i++) {
			newSet.SET.pb(SET[i] + set2.SET[i]);
		}
		sort(all(newSet.SET));
		return newSet;
	}

	Set operator+(ValueType element) {
		Set newSet;
		for (int i = 0; i < sz(SET) ; i++) {
			newSet.SET.pb(SET[i] + element);
		}
		return newSet;
	}

	Set operator*(Set & set2) {
		Set newSet;
		for (int i = 0; i < sz(SET) ; i++) {
			newSet.SET.pb(SET[i] * set2.SET[i]);
		}
		sort(all(newSet.SET));
		return newSet;
	}

	Set operator-(Set & set2) {
		Set newSet;
		for (int i = 0; i < sz(SET) ; i++) {
			newSet.SET.pb(SET[i] - set2.SET[i]);
		}
		sort(all(newSet.SET));
		return newSet;
	}

	friend ostream& operator<<(ostream & out, Set<ValueType> & setObj);

};

template<typename ValueType>
ostream& operator<<(ostream& out, Set<ValueType>& setObj) {
	for (int i = 0; i < sz(setObj) ; i++) {
		out << setObj.SET[i] << " ";
	}
	return out;
}

// In addition Set class supports the following operations:
// Stream insertion using the << operator --> done (Y)
// Deep copying for the copy constructor and assignment op
// Iteration to access beginning & end of the set and apply ++

int main() {
	Set<int> s, s1;
	s.ins(5);
	s.ins(7);
	s.ins(6);
	s.ins(3);
	s.ins(9);
	cout << s.size() << endl;

	cout << s;

	return 0;
}
