#include <iostream>
#include <algorithm>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;

#define sz(x) (int)x.size()
#define round(x) (int)(x + 0.5)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define ins insert
#define getmax(a,b) ((a) > (b) ? (a) : (b))
#define getmin(a,b) ((a) > (b) ? (b) : (a))
#define mms(x,n,s) memset(x, n, sizeof(x) * s)
#define CV(x,n) count(all(x),(n))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define rep(i, x, n) for (int (i) = (x); (i) < (n); (i)++)


const ll OO = 1e8;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int d8i [] = {0, 0, 1, -1, 1, 1, -1, -1};
int d8j [] = {1, -1, 0, 0, 1, -1, 1, -1};

   /*           \\^//           /*
   | |    Magic Starts Here     | |
   */           // \\           * /


vector<pair<char, double> > frequencies; // vector holding frequencies
set<char> availableLetters; 			 // set holding the unique characters
string word;
long double finalRange; // the final compressed value

long double getFrequency(char c) {
	long double t;
	FOR(i, sz(frequencies))
		if (frequencies[i].first == c){
			t = frequencies[i].second; break;
		}
	return t;
}

long double getPreviousFrequency(char c) {
	long double t;
	FOR(i, sz(frequencies))
		if (frequencies[i].first == c) {
			t = frequencies[i - 1].second;
			break;
		}
	return t;
}

void compress() {
	long double lower = 0, upper = 1;
	long double old_lower;
	FOR(i, sz(word)) {
		old_lower = lower;
		if (word[i] == 'a')
			lower = old_lower + (upper - old_lower) * 0;
		else
			lower = old_lower + (upper - old_lower) * getPreviousFrequency(word[i]);

		upper = old_lower + (upper - old_lower) * getFrequency(word[i]);
	}
	finalRange = (lower + upper) / 2.0;
}

void deCompress() {
	int sizeOfInputData = sz(word);
	long double lower = 0, upper = 1;
	long double search = finalRange;
	long double old_lower;
	char wanted;
	while(sizeOfInputData--) {
		FOR(i, sz(frequencies)) {
			old_lower = lower;
			if (finalRange <= frequencies[i].second) {
				wanted = frequencies[i].first;
				cout << wanted;
				if (wanted == 'a')
					lower = old_lower + (upper - old_lower) * 0;
				else
					lower = old_lower + (upper - old_lower) * getPreviousFrequency(wanted);
				upper = old_lower + (upper - old_lower) * getFrequency(wanted);
			}
			// finalRange must be updated here
		}
	}
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("arith.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	cin >> word; // get input


	// insert all letters in a set of distinct letters
	FOR(i, sz(word)) availableLetters.ins(word[i]);

	/**
	 * store in a vector all the letters and the corresponding frequency
	 */
	set<char>::iterator it = availableLetters.begin();
	for (; it != availableLetters.end(); ++it)
	frequencies.push_back(make_pair(*it, ((double)count(all(word), *it) / sz(word))));

	// calculate cumulative frequency
	rep(i, 1, sz(frequencies)) frequencies[i].second +=frequencies[i - 1].second;

	compress(); // standard input written on a file
	cout << sz(word) << endl;
	cout << finalRange << endl;
	deCompress(); // decompressed string written on the same file
	return 0;
}














