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

class TaxTable {
public:int income(int taxAmount)
	{

	int x = taxAmount;

	if(x > 18475 && x < 22787.5)
	{
		x = Round((taxAmount + 6525) / 0.25);
		return int(x);
	}
	else if (x > 22787.5 && x < 39979.5)
	{
		x = Round((taxAmount + 10042.5) / 0.28);
		return int(x);
	}
	else if (x > 39979.5 && x < 86328)
	{
		x = Round((taxAmount + 18975) / 0.33);
		return int(x);
	}
	else if (x > 86328)
	{
		x = Round((taxAmount + 25357) / 0.35);
		return int(x);
	}

	return -1;
	}
};


int main ()
{
	TaxTable c;
	cout << c.income(86328);

		return 0;
}
