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

int value (string x)
{
	stringstream ss;
	int val;
	string op;

	ss << x;
	ss >> op >> val;
	if(op == "C")
		return val;

	return -val;
}

class AccountBalance {
public:int processTransactions(int startingBalance, vector <string> transactions)
{
	for (int i = 0; i < (int)transactions.size(); i++)
	{
		startingBalance += value(transactions[i]);
	}
	return startingBalance;
}
};

int main()
{
	vector <string> x(3);
		 x[0] = "C 1000";
		 x[1] = "D 500";
		 x[2] = "D 350";

		 AccountBalance d;
		 cout << d.processTransactions(100 , x);

	return 0;
}

