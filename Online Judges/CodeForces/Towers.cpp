#include <iostream>
#include <vector>
#include <string>
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
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef pair<int, int> pii;

int main() {
	int n , l , max = 0 , mode;
	vi v;
	si s;
	scanf("%i", &n);
	while(n--) {
		scanf("%i", &l);
		v.pb(l);
		s.ins(l);
	}
	for (int i = 0; i < sz(v); i++) {
		mode = count( all(v) , v[i]);
		if (mode > max)
			max = mode;
	}
	cout << max << " " << sz(s) << endl;
	return 0;
}
