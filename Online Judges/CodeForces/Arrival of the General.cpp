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

	int n, min = 0, min_i, max = 0, max_i, cnt = 0;

	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
			max_i = i;
		}
	}

	for (int i = max_i; i >= 0; i--) {
		if (i == 0)
			break;
		swap(v[i] , v[i - 1]);
		cnt++;
	}

	min = v[0];

	for (int i = 0; i < n; i++) {
		if (v[i] <= min) {
			min = v[i];
			min_i = i;
		}
	}

	for (int i = min_i; i < n; i++) {
		if (i == n - 1)
			break;
		swap(v[i], v[i + 1]);
		cnt++;
	}
	cout << cnt;
	return 0;
}
