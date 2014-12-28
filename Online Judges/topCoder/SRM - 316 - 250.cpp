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


//score 209.26
class HiddenMessage {
public:string getMessage(string text) {

	string s = "" , y = "";
	stringstream ss;
	ss << text;
	while (ss >> y)
	{
		s += y[0];
	}
	return s;
}
};

int main ()
{
	string x = "compete online design event rating";
	HiddenMessage d;
	cout << d.getMessage(x);
}
