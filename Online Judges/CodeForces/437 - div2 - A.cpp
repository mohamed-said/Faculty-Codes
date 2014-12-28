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

string arr[4];

int foo() {
	int ans = -1;
	int cnt = 0;
	bool yes = 1;
	FOR(i, 4) {
		yes = true;
		FOR(j, 4) {
			if (j == i) continue;
			if (sz(arr[i]) <= sz(arr[j]) / 2) continue;
			else yes = false;
		}
		if (yes) {
			ans = i;
			++cnt;
		}
	}
	if (cnt > 1) return -1;
	return ans;
}

int bar() {
	int ans = -1;
	int cnt = 0;
	bool yes = false;
	FOR(i, 4){
		yes = true;
		FOR(j, 4) {
			if (j == i) continue;
			if (sz(arr[i]) >= 2 * sz(arr[j])) continue;
			else yes = false;
		}
		if (yes) {
			ans = i;
			++cnt;
		}
	}
	if (cnt > 1) return -1;
	return ans;
}

 int main() {

	#ifndef ONLINE_JUDGE
		// freopen("", "rt", stdin);
		//freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);

	string x;
	FOR(i, 4) {
		getline(cin, x);
		arr[i] = x.substr(2);
	}

	int s = foo();
	int l = bar();
	if (s != -1 && l != -1) cout << "C";
	else if (s != -1) cout << char(s + 'A');
	else if (l != -1) cout << char(l + 'A');
	else cout << "C";

	return 0;
}
