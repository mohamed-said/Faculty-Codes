#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class SubstitutionCode {
public:int getValue(string key, string code)
	{
	string x = "";
	int y = 0;
	for (unsigned int i = 0; i < code.size(); i++)
	{
		for (unsigned int j = 0; j < key.size(); j++)
		{
			if (code[i] == key[j])
			{
				if(j == key.size()-1)
					x += "0";
				else {
				stringstream ss;
				ss << (j+1);
				string str = ss.str();
				x += str;
				}
			}
		}
	}

	stringstream ss2(x);
	ss2 >> y;
	return y;
	}
};
