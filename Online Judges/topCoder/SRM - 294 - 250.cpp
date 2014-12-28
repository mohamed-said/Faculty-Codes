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

class ThreeCardMonte {
public:string position(string swaps) {

	string ace = "M";
	for (int i = 0; i < (int)swaps.size(); i++)
	{
		if(swaps[i] == 'L')
		{
			if(ace == "M")
				ace = "L";
			else if (ace == "L")
				ace = "M";
			else if (ace == "R")
				continue;
		}
		else if (swaps[i] == 'R')
		{
			if(ace == "M")
				ace = "R";
			else if (ace == "R")
				ace = "M";
			else if (ace == "L")
				continue;
		}
		else if (swaps[i] == 'E')
		{
			if(ace == "M")
				continue;
			else if (ace == "R")
				ace = "L";
			else if (ace == "L")
				ace = "R";
		}
		else
			continue;
	}
	return ace;
}
};

int main()
{

	string x = "FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL";
	ThreeCardMonte d;
	cout << d.position(x);

//	string st = "JAJ";
//	for (int i = 0; i < (int)x.size(); i++)
//	{
//		if(x[i] == 'L') swap(st[0] , st[1]);
//		if(x[i] == 'R') swap(st[1] , st[2]);
//		if(x[i] == 'E') swap(st[0] , st[2]);
//	}
//
//	if(st[0] == 'A')cout << "L";
//	if(st[1] == 'A')cout << "M";
//	if(st[2] == 'A')cout << "R";


	return 0;
}

