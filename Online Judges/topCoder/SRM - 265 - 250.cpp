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

using namespace std;

class FontSize {
public:
int getPixelWidth(string sentence, vector <int> uppercase, vector <int> lowercase)
{
	int res = 0;
	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		if(isupper(sentence[i]))
		{
			res += uppercase[int(sentence[i]) - 65];
			if(i != sentence.size() - 1)
				res++;
		}

		else if (islower(sentence[i]))
		{
			res += lowercase[int(sentence[i]) - 97];
			if(i != sentence.size() - 1)
				res++;
		}
		else
		{
			res += 3;
			if(i != sentence.size() - 1)
				res++;
		}

	}
	return res;
}
};
