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

class DerivativeSequence {
public:vector <int> derSeq(vector <int> a, int n)
{
	vector<int> x(a.size() - n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)a.size() - 1; j++)
		{
			a[j] = (a[j + 1] - a[j]);
		}

	}
	for (int i = 0; i < (int)x.size(); i++)
	{
		x[i] = a[i];
	}
	return x;
}
};
