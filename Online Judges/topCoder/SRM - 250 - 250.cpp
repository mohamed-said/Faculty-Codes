#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

class ColorCode
{
public : long long getOhms(vector <string> code)
	{
	long long int y = 0;


			if (code[0] == "black")
				y = 0 * 10;
			else if (code[0] == "brown")
				y = 1 * 10;
			else if (code[0] == "red")
				y = 2 * 10;
			else if (code[0] == "orange")
				y = 3 * 10;
			else if (code[0] == "yellow")
				y = 4 * 10;
			else if (code[0] == "green")
				y = 5 * 10;
			else if (code[0] == "blue")
				y = 6 * 10;
			else if (code[0] == "violet")
				y = 7 * 10;
			else if (code[0] == "grey")
				y = 8 * 10;
			else if (code[0] == "white")
				y = 9 * 10;


			if (code[1] == "black")
					y += 0;
				else if (code[1] == "brown")
					y += 1;
				else if (code[1] == "red")
					y += 2;
				else if (code[1] == "orange")
					y += 3;
				else if (code[1] == "yellow")
					y += 4;
				else if (code[1] == "green")
					y += 5;
				else if (code[1] == "blue")
					y += 6;
				else if (code[1] == "violet")
					y += 7;
				else if (code[1] == "grey")
					y += 8;
				else if (code[1] == "white")
					y += 9;


			if (code[2] == "black")
					y *= 1;
				else if (code[2] == "brown")
					y *= 10;
				else if (code[2] == "red")
					y *= 100;
				else if (code[2] == "orange")
					y *= 1000;
				else if (code[2] == "yellow")
					y *= 10000;
				else if (code[2] == "green")
					y *= 100000;
				else if (code[2] == "blue")
					y *= 1000000;
				else if (code[2] == "violet")
					y *= 10000000;
				else if (code[2] == "grey")
					y *= 100000000;
				else if (code[2] == "white")
					y *= 1000000000;

			return y;

	}
};

int main () {

	vector<string> x(3);
		 x[0] = "brown";
		 x[1] = "red";
		 x[2] = "orange";

	ColorCode d;
	cout << d.getOhms(x);

}
