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

class CrossWordPuzzle {
public: int countWords(vector <string> board, int size)
{
	int res = 0 , x = 0;

	for (unsigned int i = 0; i < board.size(); i++)
	{
		x = 0;
		for (unsigned int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] == '.')
			{
				x++;
			}
			else if (board[i][j] == 'X')
			{
				if(x == size)
				{
					res++;
				}
				x = 0;
			}
		}
		if(x == size)
			res++;
	}
	return res;
}
};
