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
	int n, cnt = 0, sum = 0, sum2 = 0;
	cin >> n;
	vi v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
		sum2 += v[i];

	sort(all(v));

	for (int i = n - 1; i >= 0; i--) {
		cnt++;
		sum += v[i];
		sum2 -= v[i];
		if(sum > sum2)
			break;
	}
	cout << cnt;
	return 0;
}
