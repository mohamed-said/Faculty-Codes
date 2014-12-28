#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SpreadsheetColumn
{
public:string getLabel(int column)
{
	int count = 26;
	bool ok = false;
	string col = "";
	if (column <= 26)
	{
		col = char('A' + column - 1);
		return col;
	} else {

		for (int i = 65; i < 91; i++)
		{
			for (int j = 65; j < 91; j++)
			{
				count++;
				if (column == count)
				{
				col += char(i);
				col += char(j);
				ok = true;
				break;
				}
			}
			if(ok) break;
		}
		return col;
	}
}
};
