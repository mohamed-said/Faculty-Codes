#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toStr(int x)
{

	string s;
	stringstream ss;
	ss << x;
	ss >> s;
	return s;
}

class DivToZero
{
public:
string lastTwo(int num, int factor)
{
	num /= 100;
	num *= 100;
	while (num % factor != 0)
	{
		num++;
	}
	int a , b;
	a = (num % 10);
	b = (((num - a)/10) % 10);
	string s;
	s = toStr(b) + toStr(a);

	return s;

}
};
