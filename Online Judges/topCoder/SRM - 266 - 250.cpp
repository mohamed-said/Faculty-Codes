#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>

#define Round(x) int(x + 0.5)

using namespace std;

class SwimmersDelight {
public:int longestJump(vector <int> x, vector <int> y)
{
	vector<int> final;

	double a , b , c;

	int res;

	a = Round(hypot(0 - x[0] , y[0] - y[0]));
	b = Round(hypot(x[0] - x[1] , y[0] - y[1]));
	c = Round(hypot(x[1] - 10 , y[1] - y[1]));

	res = (int)max(a , max(b , c));
	final.push_back(res);

	a = Round(hypot(0 - x[1] , y[1] - y[1]));
	b = Round(hypot(x[1] - x[0] , y[1] - y[0]));
	c = Round(hypot(x[0] - 10 , y[0] - y[1]));

	res = (int)max(a , max(b , c));
	final.push_back(res);

	a = Round(hypot(0 - x[0] , y[0] - y[0]));
	b = Round(hypot(x[0] - 10 , y[0] - y[0]));

	res = (int)max(a , b);
	final.push_back(res);

	a = Round(hypot(0 - x[1] , y[1] - y[1]));
	b = Round(hypot(x[1] - 10 , y[1] - y[1]));

	res = (int)max(a , b);
	final.push_back(res);

	sort(final.begin() , final.begin() + 4);
	return (int)ceil(final[0]);

}
};
