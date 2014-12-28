#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class CompetitionStatistics
{
public:int consecutiveGrowth(vector <int> ratingChanges)
{
	int x = 0 , max = 0;

	for (int i = 0; i < ratingChanges.size(); i++)
	{
		if(ratingChanges[i] > 0)
		{
			x++;
			if(x > max)
			max = x;

		}
		else if (ratingChanges[i] <= 0)
		{
			x = 0;
		}
	}

		return max;

}
};
