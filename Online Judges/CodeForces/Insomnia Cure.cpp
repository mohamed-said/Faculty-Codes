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

int main() {
	int k, l, m, n, d, cnt = 0;
	cin >> k >> l >> m >> n >> d;
	for (int i = 0; i < d; i++) {
		if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}
