#include <iostream>
#include <vector>
using namespace std;

class GridGenerator {
public:
	int generate(vector<int> row, vector<int> col)
	{

		vector<int> x(row.size() - 1);
		vector<int> x2(row.size() - 1);

		x[0] = col[1];
		for (unsigned int j = 0; j < row.size() - 1; j++)
		{
			if (j == 0)
				x[j] = row[j] + row[j + 1] + x[j];
			else
				x[j] = row[j] + row[j + 1] + x[j - 1];
		}

		for (unsigned int j = 0; j < row.size() - 1; j++)
		{
			x2[j] = x[j];
		}

		for (unsigned int edd = 1; edd < row.size() - 1; edd++)
		{
			for (unsigned int k = 0; k < row.size() - 1; k++)
			{
				if (k == 0)
					x[k] = col[edd] + col[edd + 1] + x2[k];
				else
					x[k] = x2[k - 1] + x2[k] + x[k - 1];
			}

			for (unsigned int w = 0; w < row.size() - 1; w++)
			{
				x2[w] = x[w];
			}
		}

		return x.back();

	}
};


	int generate(vector<int> row, vector<int> col) {
		int size = row.size();
		int arr[11][11];
		for (int i = 0; i < size; i++)
			arr[0][i] = row[i];
		for (int i = 0; i < size; i++)
			arr[i][0] = col[i];

		for (int i = 1; i < size; i++)
			for (int j = 1; j < size; j++)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1] + arr[i - 1][j];
		return arr[size - 1][size - 1];
	}
