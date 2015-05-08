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
#include <ctime>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

int main() {
	int Q;
	int demand, Time, sales, min, max;
	int clock = 1, TotlDemand = 0, Totalsold = 0, store = 0;
	double GPR, HC, SC;
	double TSC = 0, THC = 0, TGPR = 0, NetProfit = 0, AP = 0;
	double temp1 = 0, temp2 = 0;
	cout << "Quantity        : ";
	cin >> Q;
	cout << "GPR             : ";
	cin >> GPR;
	cout << "Shortage cost   : ";
	cin >> SC;
	cout << "Holding cost    : ";
	cin >> HC;
	cout << "Run time        : ";
	cin >> Time;
	cout << "Mininmum demand : ";
	cin >> min;
	cout << "Maximum demand  : ";
	cin >> max;

	cout << endl << endl;
	srand(time(NULL));

	while (clock <= Time) {
		demand = (rand() % (max - min)) + min;
		store += Q;

		if (demand <= store)
			sales = demand;
		else
			sales = store;

		store -= sales;
		temp1 = HC * store;
		temp2 = SC * (demand - sales);

		TGPR = GPR * sales;

		THC += temp1;
		TSC += temp2;


		NetProfit = TGPR - temp1 - temp2;
		Totalsold += sales;
		TotlDemand += demand;
		AP += NetProfit;

		cout << "week " << clock << " :\n" << "\tDemand = " << demand << endl
				<< "\tSales  = " << sales << endl << "\tStore  = " << store
				<< endl << "\tTHC    = " << temp1 << endl << "\tTSC    = " << temp2
				<< endl << "\tTGPR   = " << TGPR << endl << endl;

		clock++;
	}

	cout << endl << endl;
	cout << "Service Level      = "
			<< ((double) (Totalsold) / (double) (TotlDemand)) * 100 << " %"
			<< endl;
	cout << "Average Net Profit = " << (double) AP / (double) Time << endl
			<< endl;

	cout << "Average Holding Cost = " << (double)THC / (double)Time << endl;
	cout << "Average Shortage Cost = " << (double)TSC / (double)Time << endl;

	return 0;
}
