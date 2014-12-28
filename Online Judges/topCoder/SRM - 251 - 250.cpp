#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

class Elections {
public :
int visit(vector <string> likelihoods)
{
  double idx = 0 , counter_ones = 0 , min = 100;
	for (unsigned int i = 0; i < likelihoods.size(); i++)
	{
	    for (unsigned int j = 0; j < likelihoods[i].size(); j++)
	    {
	        if (likelihoods[i][j] == '1')
	        counter_ones++;
	    }

	    // fe el ta5zeeen yatakarrab

	    if ( counter_ones * 100 / likelihoods[i].size() + 0.000000001 < min) // fe el condition la yatakarab :@
	    {
	    	min = counter_ones * 100 / likelihoods[i].size() ;
	    	idx = i;
	    }

	    counter_ones = 0;

	}

	return idx;

}

};
