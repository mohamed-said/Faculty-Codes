#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DiagonalDisproportion {
public:
	int getDisproportion(vector<string> matrix) {
		int main_d = 0, coll_d = 0, res = 0;

		for (unsigned int i = 0; i < matrix.size(); i++) {

			if (matrix[i][i] == '0')
				main_d += 0;
			else if (matrix[i][i] == '1')
				main_d += 1;
			else if (matrix[i][i] == '2')
				main_d += 2;
			else if (matrix[i][i] == '3')
				main_d += 3;
			else if (matrix[i][i] == '4')
				main_d += 4;
			else if (matrix[i][i] == '5')
				main_d += 5;
			else if (matrix[i][i] == '6')
				main_d += 6;
			else if (matrix[i][i] == '7')
				main_d += 7;
			else if (matrix[i][i] == '8')
				main_d += 8;
			else if (matrix[i][i] == '9')
				main_d += 9;

		}

		for (unsigned int k = 0, m = matrix.size() - 1;
				k < matrix.size() && m >= 0; k++, m--) {
			if (matrix[k][m] == '0')
				main_d += 0;
			else if (matrix[k][m] == '1')
				coll_d += 1;
			else if (matrix[k][m] == '2')
				coll_d += 2;
			else if (matrix[k][m] == '3')
				coll_d += 3;
			else if (matrix[k][m] == '4')
				coll_d += 4;
			else if (matrix[k][m] == '5')
				coll_d += 5;
			else if (matrix[k][m] == '6')
				coll_d += 6;
			else if (matrix[k][m] == '7')
				coll_d += 7;
			else if (matrix[k][m] == '8')
				coll_d += 8;
			else if (matrix[k][m] == '9')
				coll_d += 9;

		}
		res = main_d - coll_d;
		return res;
	}
};
