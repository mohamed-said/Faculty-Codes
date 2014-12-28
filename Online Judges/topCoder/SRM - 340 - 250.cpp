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

class CssPropertyConverter {
public:string getCamelized(string cssPropertyName)
{
	for (int i = 0; i < (int)cssPropertyName.size(); i++)
	{
		if(cssPropertyName[i] == '-')
		{
			cssPropertyName[i + 1] = toupper(cssPropertyName[i + 1]);
			cssPropertyName.erase(i , 1);
		}
	}

	return cssPropertyName;
}
};

int main ()
{

	CssPropertyConverter d;
	cout << d.getCamelized("top-border-width");
	return 0;
}
