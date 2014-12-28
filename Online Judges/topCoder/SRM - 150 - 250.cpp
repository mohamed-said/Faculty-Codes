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
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
using namespace __gnu_cxx;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

class WidgetRepairs {
public:
	int days(vector<int> arrivals, int numPerDay) {
		int sum = 0;

		if (sz(arrivals) == 1) {
			sum += arrivals[0] / numPerDay;
			return sum + ((arrivals[0] % numPerDay) >= 1);
		}

		for (int i = 0; i < sz(arrivals) - 1; i++) {
			if (arrivals[i] > numPerDay) {
				arrivals[i + 1] = arrivals[i + 1] + (arrivals[i] - numPerDay);
				arrivals[i] = numPerDay;
			}
		}

		sum = sum + arrivals[sz(arrivals) - 1] / numPerDay
				+ (arrivals[sz(arrivals) - 1] % numPerDay >= 1);

		for (int i = 0; i < sz(arrivals) - 1; i++)
			sum += (arrivals[i] != 0);

		return sum;
	}
};

int main() {
	int arr[] = { 100, 3 };
	vector<int> vec(arr, arr + (sizeof(arr) / sizeof(int)));

	WidgetRepairs d;
	cout << d.days(vec, 10);

	return 0;
}
