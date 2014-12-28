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
	int n, a, b, sum = 0, max = 0;
	scanf("%i" , &n);
	while(n--) {
		scanf("%i", &a);
		sum -= a;
		scanf("%i", &b);
		sum += b;

		if(sum > max)
			max = sum;
	}
	printf("%i", max);
	return 0;
}
