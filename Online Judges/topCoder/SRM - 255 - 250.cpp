#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class SequenceOfNumbers
{
public: vector <string> rearrange(vector <string> sequence)
		{
	vector<int> numbers;
	vector<string> sorted;
	string str;
	int nums;
	for (unsigned int i = 0; i < sequence.size(); i++)
	{
		stringstream ss(sequence[i]);
		ss >> nums;
		numbers.push_back(nums);
	}

	sort(numbers.begin() , numbers.begin()+numbers.size());

	for (unsigned int j = 0; j < numbers.size(); j++)
	{
		stringstream ss2;
		ss2 << numbers[j];
		str = ss2.str();
		sorted.push_back(str);
	}

	return sorted;
		}
};
