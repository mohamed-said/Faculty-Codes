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

int arr[8];

class YahtzeeScore {
public:

	int maxPoints(vector<int> toss) {
		memset(arr, 0, 8);
		int max = 0;
		for (int i = 0; i < sz(toss); i++) {
			arr[toss[i]] += toss[i];
		}

		for (int i = 0; i < 8; i++) {
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}

};

int main() {
	int arr[] = { 6, 4, 1, 1, 3 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	YahtzeeScore d;
	cout << d.maxPoints(vec);
	return 0;
}
