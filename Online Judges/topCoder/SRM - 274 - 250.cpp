#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover
{
	// [1][5][5][1][6][1]
public : vector <int> process(vector <int> sequence)
		{
	for (int i = sequence.size()-1; i >= 0; i--)
	{
		for (int j = sequence.size()-2; j >= 0; j--)
		{
			if ( i == j)
				j--;
			if(sequence[i] == sequence[j])
				sequence.erase(sequence.begin()+j);
		}
	}

	return sequence;
		}
};
