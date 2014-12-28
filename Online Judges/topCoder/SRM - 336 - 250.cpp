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

class VowelLatin {
public: string translate(string word)
{
	string temp = "" , temp2 = "";

	for (int i = 0; i < (int)word.size(); i++)
	{
		if(word[i] == ('a')
		|| word[i] == ('e')
		|| word[i] == ('i')
		|| word[i] == ('o')
		|| word[i] == ('u')
		|| word[i] == ('A')
		|| word[i] == ('E')
		|| word[i] == ('I')
		|| word[i] == ('O')
		|| word[i] == ('U')
		)
		{
			temp += word[i];
		}
		else
			temp2 += word[i];

	}

	return (temp2 + temp);
}
};

int main ()
{
	VowelLatin d;
	cout << d.translate("aeioOa"); //"Oaeioa"

	return 0;
}
