#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class SpeedTyper
   {
public:string lettersToPractice(string letters, vector <int> times)
   {
int sum = times[0] , avg = 0;
   string d = "";
   for (unsigned int i = 1; i < letters.size(); i++)
	{
	sum += ( times[i] - times[i-1]);
	}
   avg = ( sum / letters.size() );

   if(times[0] > avg)
	d += letters[0];
   for (unsigned int j = 1; j < letters.size(); j++)
	{
	if ( (times[j] - times[j-1] ) > avg )
	    d += letters[j];
	}
   return d;

   }
   };
