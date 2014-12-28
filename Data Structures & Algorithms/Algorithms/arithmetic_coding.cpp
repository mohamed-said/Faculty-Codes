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

int main() {

	#ifndef ONLINE_JUDGE
	freopen("data.txt", "rt", stdin);
		//freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);
	vector<pair<char, double> > frequencies;
	string word;
	set<char> availableLetters;
	cin >> word; // get input
	FOR(i, sz(word)) availableLetters.ins(word[i]);
	set<char>::iterator it = availableLetters.begin();
	for (; it != availableLetters.end(); ++it) {
		int n = count(all(word), *it);
		frequencies.push_back(make_pair(*it, (double)n / double(sz(word))));
	}
	rep(i, 1, sz(frequencies)) frequencies[i].second +=frequencies[i - 1].second;
	long double lower = 0, upper = 1;
	FOR(i, sz(frequencies)) {
		if (!i) {
			lower = lower + (upper - lower) * 0;
			upper = lower + (upper - lower) * frequencies[i].second;
		} else {
			lower = lower + (upper - lower) * frequencies[i - 1].second;
			upper = lower + (upper - lower) * frequencies[i].second;
		}
		cout << lower << " " << upper << endl;
	}

//	cout << lower << " " << upper << endl;

	return 0;
}
