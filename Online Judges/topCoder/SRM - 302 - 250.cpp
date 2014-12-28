#include <iostream>
#include <vector>
#include <string>
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
#include <stdio.h>
#include <stdlib.h>


#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()

using namespace std;

class NounReform {
public:vector <string> makePlural(vector <string> nouns)
{
	string::iterator it;
	for (int i = 0; i < (int)nouns.size(); i++)
	{
			if (nouns[i][nouns[i].size() - 1] == 's'
				||nouns[i][nouns[i].size() - 1] == 'z'
				|| nouns[i][nouns[i].size() - 1] == 'x'
				|| (nouns[i][nouns[i].size() - 2] == 's' && nouns[i][nouns[i].size() - 1] == 'h')
				|| (nouns[i][nouns[i].size() - 2] == 'c' && nouns[i][nouns[i].size() - 1] == 'h')
				)
				nouns[i] += "es";

			else if ((nouns[i][nouns[i].size() - 2] == 'a' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] == 'e' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] == 'i' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] == 'o' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] == 'u' && nouns[i][nouns[i].size() - 1] == 'y')
					)
				nouns[i] += "s";

			else if ((nouns[i][nouns[i].size() - 2] != 'a' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] != 'e' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] != 'i' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] != 'o' && nouns[i][nouns[i].size() - 1] == 'y')
					|| (nouns[i][nouns[i].size() - 2] != 'u' && nouns[i][nouns[i].size() - 1] == 'y')
					)
			{
				nouns[i].erase(nouns[i].size() - 1 , 1);
				nouns[i] += "ies";
			}
			else
				nouns[i] += "s";
	}

	return  nouns;
}
};
