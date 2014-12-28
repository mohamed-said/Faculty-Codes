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

// submit after 40 mins
class AccessChanger {
public: vector<string> convert(vector<string> program)
{
	for (unsigned int i = 0; i < program.size(); i++)
	{
		for (unsigned j = 0; j < program[i].size(); j++)
		{
			if(program[i][j] == '-' && program[i][j + 1] == '>')
			{
				program[i].replace(j , 2 , ".");
			}
			else if (program[i][j] == '/' && program[i][j + 1] == '/')
				break;
		}


	}

	return program;
}
};



int main()
{
	vector<string> x(1) , y(1);
	 x[0] = "->-> // two successive arrows ->->";
	 x[1] = "---";
	 x[2] = "> // the parted arrow";
	 x[3] = "t->go(); // a=1, b=2 --> a=2, b=3";


	 AccessChanger A;
	 y = A.convert(x);

	 for (unsigned int i = 0; i < y.size(); i++)
	 {
		 cout << y[i] << endl;
	 }

	return 0;
}

