#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CheckFunction
{
public : int newFunction(string code)
{
	int sum = 0;
	for (int i = 0; i < code.size(); i++)
	{
		if (code[i] == '0')
			sum += 6;
		else if (code[i] == '1')
			sum += 2;
		else if (code[i] == '2')
			sum += 5;
		else if (code[i] == '3')
			sum += 5;
		else if (code[i] == '4')
			sum += 4;
		else if (code[i] == '5')
			sum += 5;
		else if (code[i] == '6')
			sum += 6;
		else if (code[i] == '7')
			sum += 3;
		else if (code[i] == '8')
			sum += 7;
		else if (code[i] == '9')
			sum += 6;
	}

	return sum;

}
};
