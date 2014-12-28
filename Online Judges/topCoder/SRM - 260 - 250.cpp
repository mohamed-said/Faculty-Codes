#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class IsingModel
{
public: int energy(vector <string> spins)
{
	int E = 0;

		for (unsigned int i = 0; i < spins.size(); i++)
		{
			for (unsigned int j = 0; j < spins[i].size()-1; j++)
			{
				if( spins[i][j] == spins[i][j+1]) // {"-++" , "+-+"}
					E--;
				else
					E++;
			}
		}

		for (unsigned int i = 0; i < spins.size()-1; i++)
		{
			for (unsigned int j = 0; j < spins[i].size(); j++)
			{
				if (spins[i][j] == spins[i+1][j])
					E--;
				else
					E++;
			}
		}
		return E;

}
};
