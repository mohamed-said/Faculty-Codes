#include<cstdlib>
#include<iostream>
#include<time.h>

using namespace std;

int gendemand(float prbablty) {
	if (prbablty <= 0.01)
		return 0;
	if (prbablty <= 0.09)
		return 1;
	if (prbablty <= 0.31)
		return 2;
	if (prbablty <= 0.62)
		return 3;
	if (prbablty <= 0.83)
		return 4;
	if (prbablty <= 0.92)
		return 5;

	return 6;
}

int genleadtime(float prbablty) {
	if (prbablty <= 0.19)
		return 1;
	if (prbablty <= 0.54)
		return 2;
	if (prbablty <= 0.79)
		return 3;

	return 4;
}

int main() {
	int EOQ = 0, ROP = 0;                                   // decision variables
	int C1 = 0, C2 = 0, C3 = 0, TT = 0;                     // parameters
	int d = 0, PLT = -1, sales;                       		// environmental variables
	int v = 0, t = 0, clock = 1, TC1 = 0, TC2 = 0, TC3 = 0; // status variables
	int TC = 0;                                             // output variables
	float temp = 0.0;
	bool order_placed = false;

	cout << "EOQ: ";
	cin >> EOQ;
	cout << "ROP: ";
	cin >> ROP;
	cout << "carrying cost (LE/unit) : ";
	cin >> C1;
	cout << "ordering cost (LE/order): ";
	cin >> C2;
	cout << "shortage cost (LE/unit) : ";
	cin >> C3;
	cout << "initial stock level: ";
	cin >> v;
	cout << "Run time (days)    : ";
	cin >> TT;

	srand(time(NULL));
	while (clock <= TT) {
		temp = (float) (rand() % 100);
		temp /= 100;
		d = gendemand(temp);

		if (clock == t) {
			v += EOQ;
			order_placed = false;
		}

		if (v >= d)
			sales = d;
		else
			sales = v;

		v -= sales;
		TC1 = C1 * v;
		TC2 = 0;
		TC3 = C3 * (d - sales);

		if ((v <= ROP) && (!(order_placed))) {
			temp = (float) (rand() % 100);
			temp /= 100;
			PLT = genleadtime(temp);
			t = clock + PLT;
			order_placed = true;
			TC2 = C2;
		}

		cout << "day " << clock << ":\n" << "\tlead time = " << PLT << endl
				<< "\tdemand = " << d << endl << "\tsales  = " << sales << endl
				<< "\tstock  = " << v << endl;

		TC += (TC1 + TC2 + TC3);
		clock++;
	}

	cout << "\n\nTotal inventory cost = " << TC << " LE" << endl << endl;
	return 0;
}
