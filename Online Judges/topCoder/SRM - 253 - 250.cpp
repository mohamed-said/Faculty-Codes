#include <string>
#include <vector>
using namespace std;

class ObjectPacking
{
public:int smallBox(int objWidth, int objLength, vector <int> boxWidth, vector <int> boxLength)
{
	int box = 0 , min = 1000000;
	bool key = 0;

		for (unsigned int i = 0; i < boxWidth.size(); i++)
		{
			if ( (boxWidth[i] >= objWidth && boxLength[i] >= objLength) || (boxLength[i] >= objWidth && boxWidth[i] >= objLength) )
			{
				if ( (boxWidth[i]*boxLength[i]) <= min)
				{
					min = (boxWidth[i]*boxLength[i]);
					box = min;
					key = 1;
				}
			}
		}

		if(key)
			return box;
		else
			return -1;

}
};
