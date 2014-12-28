#include <iostream>
using namespace std;

class UniqueDigits
{
public: int count(int n)
{
int counter = 0, temp = 0, s = 0 , temp2 = 0;
   bool key = 1;
   cin >> n;

   for (int i = 1; i < n; i++)
	{
	temp = i;
	while (temp > 0)
	    {
	    s = temp % 10;
	    temp /= 10;
	    temp2 = temp;
	    key = 1;

////////////////////////////////
	    while (temp2 > 0)
		{
		if (s == temp2 % 10)
		    {
		    key = 0;
		    break;
		    }
		temp2 /= 10;
		}
	    if(key == 0)
		break;
	    }
//////////////////////////////////
	if (key)
	    counter++;
	}

   return counter;

}
};
