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

class HingedDoor {
public: int numSwings(int initialAngle, int reduction)
{
	int res = 0;
	float x = initialAngle;
	while(x > 5.0)
	{
		res++;
		x /= reduction;
	}
	return res;
}
};

int main() {

	HingedDoor d;
	cout << d.numSwings(3 , 3);

	return 0;
}
