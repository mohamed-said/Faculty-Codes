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

class FixTheAverage {
public:double add(vector <double> list, double target)
{
	double Vsum = 0 , x;
	float size = list.size();
	for (int i = 0; i < (int)list.size(); i++)
	{
		Vsum += list[i];
	}

	x = -(size + 1) * ((Vsum / (size + 1)) - target);
	return x;

}
};
