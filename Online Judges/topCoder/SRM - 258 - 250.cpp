#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ClassScores
{
public:vector <int> findMode(vector <int> scores)
		{
	int x = 0 , max = 0 , mode = 0;
	vector<int> beed;
	for (unsigned int i = 0; i < scores.size(); i++)
	{
		for (unsigned int j = 0; j < scores.size(); j++)
		{
			if (scores[i] == scores[j])
				x++;
		}
		if (x > max){
			max = x;
			mode = scores[i];
		}
		x = 0;
	}
	beed.push_back(mode);
	x = 0;
	for (unsigned int i = 0; i < scores.size(); i++)
		{
			for (unsigned int j = 0; j < scores.size(); j++)
			{
				if (scores[i] == scores[j])
					x++;
			}
			if (x == max)
			{
				bool key = 1;
				for (unsigned int k = 0; k < beed.size(); k++)
				{
					if(scores[i] == beed[k]){
						key = 0;
						break;
					}
				}
				if(key)
					beed.push_back(scores[i]);
			}
			x = 0;
		}
	sort(beed.begin() , beed.end());
	return beed;
		}
};
