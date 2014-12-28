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

class GreatFairyWar {
public:
	int minHP(vector <int> dps, vector <int> hp) {
		int sum = 0, sum2 = 0, sum3 = 0;
		for (int i = 0; i < sz(dps); i++) {
			sum += dps[i];
		}

		for (int i = 0; i < sz(hp); i++) {
			sum3 += hp[i] * (sum - sum2);
			sum2 += dps[i];
		}
		return sum3;
	}
};

int main () {

		int arr[] = {1, 2};
		int arr2[] = {3, 4};
		vector<int> vec(arr, arr + sizeof(arr) / sizeof(*arr));
		vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));

		GreatFairyWar d;
		cout << d.minHP(vec, vec2);


	return 0;
}
