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

class GradingSystem
{
public:
int fairness(vector <int> scores, vector <int> grades)
{
	unsigned int size = scores.size();
	int m = 0;

	vector<int> temp = grades;

	for (unsigned int i = 1; i < size; i++)
	{
		if (scores[i] >= scores[i - 1])
		{
			if(grades[i] >= grades[i - 1])
			{
				continue;
			}
			else
			{
				grades[i] = grades[i - 1];
			}
		}
	}

//	for (unsigned int k = 0; k < size; k++)
//	{
//		cout << grades[k] << " ";
//	}

	for (unsigned int j = size - 1; j > 0; j--)
	{
		if (scores[j] >= scores[j - 1])
		{
			if (temp[j] >= temp[j - 1])
			{
				continue;
			}
			else
			{
				temp[j - 1] = temp[j];
			}
		}
	}

//	for (unsigned int k = 0; k < size; k++)
//	{
//		cout << temp[k] << " ";
//	}
//

	for (unsigned int i = 0; i < size; i++)
	{
		m += grades[i] - temp[i];
	}

	return m;

}
};


//int main ()
//{
//	vector <int> scores(5);
//	scores[0] = 0;
//	scores[1] = 25;
//	scores[2] = 50;
//	scores[3] = 75;
//	scores[4] = 100;
//
//	vector <int> grades(5);
//
//	grades[0] = 8;
//	grades[1] = 6;
//	grades[2] = 3;
//	grades[3] = 1;
//	grades[4] = 0;
//
//	cout << fairness(scores , grades);
//
//	return 0;
//
//}
//
