#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

// essential functions

string toString(float f) {
  stringstream ss;
  string s;
  ss << f;
  ss >> s;
  return s;
}

float toInt(string s) {
  stringstream ss;
  float i;
  ss << s;
  ss >> i;
  return i;
}

void editFormat(string &str) {
  str.insert(1, " ");
  str.insert((int)str.size() - 1, " ");
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == ';') {
      str.insert(i, " ");
      str.insert(i + 2, " ");
      i += 2;
    }
  }
}

bool parseInput(string str) {
 return true;
}

// calculation functions

float** add(float**, float**, int, int); // done 
float** subtract(float**, float**, int, int); // done 
float** multiply(float**, float**, int, int, int, int); // done 
float** power(float**, int, int, int); // done 
void transpose(vector<vector<float> >); // done
float   determinant(int n, float**); // done 
vector<vector<float> > inverse(vector<vector<float> >, int); // done 
float** divide(float**, float**, int, int, int, int); // done
string display(float**, int, int); // done
string displayVector(vector<vector<float> >); // done

int main() {

  // dimensions
  int first_matrix_rows;
  int first_matrix_columns;

  int second_matrix_rows;
  int second_matrix_columns;


  // temporary vectors
  vector<float> nums_f, nums_s;

  // matrices
  float **matrix1, **matrix2, **res;
  
  string first_matrix;
  string second_matrix;
  char operation;


  getline(cin, first_matrix);
  editFormat(first_matrix);
  
  float temp;
  string token;
  stringstream ss;
  bool semi = false;

  ss << first_matrix;
  while(ss >> token) {
    if (token == "[" || token == "]")
      continue;
    if (token == ";" && !semi) {
      semi = true;
      first_matrix_columns = nums_f.size();
      continue;
    }
    if (token == ";")
      continue;
    temp = atof(token.c_str());
    nums_f.push_back(temp);
  }

  if (!semi) // if one row
    first_matrix_columns = nums_f.size();

  if (nums_f.size() % first_matrix_columns != 0) {
    cout << "ERROR";
    return 0;
  } else {
    first_matrix_rows = nums_f.size() / first_matrix_columns;
  }
  
  cin >> operation;
  cin.ignore();

 
  /*
   * 2D Array Initialization
   **/

  matrix1 = new float*[first_matrix_rows];
  for (int i = 0; i < first_matrix_rows; i++)
    matrix1[i] = new float[first_matrix_columns];

  int p = 0;
  for (int i = 0; i < first_matrix_rows; i++) {
    for (int j = 0; j < first_matrix_columns; j++) {
      matrix1[i][j] = nums_f[p];
      ++p;
    }
  }

  if (operation == '^') {
    int p;
    cin >> p;
     if (first_matrix_rows != first_matrix_columns) {
      cout << "ERROR";
      return 0;
    }
    if (p <= 0) {
      cout << "ERROR";
      return 0;
    }
    res = power(matrix1, first_matrix_rows, first_matrix_columns, p);
    cout << display(res, first_matrix_rows, first_matrix_columns) << endl;
  } else if (operation == 'T') {
    vector<vector<float> > mat(first_matrix_rows);
    for (int i = 0; i < first_matrix_rows; i++) {
      mat[i].resize(first_matrix_columns);
      for (int j = 0; j < mat[0].size(); j++)
        mat[i][j] = matrix1[i][j];
    }
    transpose(mat);
    //////////////////////////////////////////////////////////////////
  } else if (operation == 'D') {
    if (first_matrix_rows != first_matrix_columns) {
      cout << "ERROR";
      return 0;
    }
    cout <<  determinant(first_matrix_rows, matrix1) << endl;
  } else if (operation == 'I') {
    if (first_matrix_rows != first_matrix_columns) {
      cout << "ERROR";
      return 0;
    }
    vector<vector<float> > mat(first_matrix_rows);
    for (int i = 0; i < first_matrix_rows; i++) {
      mat[i].resize(first_matrix_columns);
      for (int j = 0; j < mat[0].size(); j++)
        mat[i][j] = matrix1[i][j];
    }
    vector<vector<float> > receive = inverse(mat, mat.size()); 
    cout << displayVector(receive) << endl;
  } else {
    getline(cin, second_matrix);
    editFormat(second_matrix);
    
    semi = false;
    ss.clear();
    ss << second_matrix;
    while(ss >> token) {
      if (token == "[" || token == "]")
        continue;
      if (token == ";" && !semi) {
        semi = true;
        second_matrix_columns = nums_s.size();
        continue;
      }
      if (token == ";")
        continue;
      temp = atof(token.c_str());
      nums_s.push_back(temp);
    }
    if (!semi)
      second_matrix_columns = nums_s.size();
    if (nums_s.size() % second_matrix_columns != 0) {
      cout << "ERROR";
      return 0;
    } else {
      second_matrix_rows = nums_s.size() / second_matrix_columns;
    }
  
    /*
     * Initializing 2D Array
     */
    
    matrix2 = new float*[second_matrix_rows];
    for (int i = 0; i < second_matrix_rows; i++)
      matrix2[i] = new float[second_matrix_columns];

    p = 0;
    for (int i = 0; i < second_matrix_rows; i++) {
      for (int j = 0; j < second_matrix_columns; j++) {
        matrix2[i][j] = nums_s[p];
        ++p;
      }
    }
    if (operation == '+') {
      if (first_matrix_rows != second_matrix_rows
          || first_matrix_columns != second_matrix_columns) {
        cout << "ERROR";
        return 0;
      }
      res = add(matrix1, matrix2, first_matrix_rows, first_matrix_columns);
      cout << display(res, first_matrix_rows, second_matrix_columns) << endl;
    } else if (operation == '-') {
       if (first_matrix_rows != second_matrix_rows
          || first_matrix_columns != second_matrix_columns) {
        cout << "ERROR";
        return 0;
      }
      res = subtract(matrix1, matrix2, first_matrix_rows, first_matrix_columns);
      cout << display(res, first_matrix_rows, second_matrix_columns) << endl;
    } else if (operation == '*') {
      if (first_matrix_columns != second_matrix_rows) {
        cout << "ERROR";
        return 0;
      }
      res = multiply(matrix1, matrix2, first_matrix_rows, first_matrix_columns,
          second_matrix_rows, second_matrix_columns);
      cout << display(res, first_matrix_rows, second_matrix_columns) << endl;
    } else if (operation == '/') {
      if (first_matrix_columns != second_matrix_rows) {
        cout << "ERROR";
        return 0;
      }
     res = divide(matrix1, matrix2, first_matrix_rows, first_matrix_columns,
          second_matrix_rows, second_matrix_columns);
      cout << display(res, first_matrix_rows, second_matrix_columns) << endl;
    }
  } 
  
  for (int i = 0; i < first_matrix_rows; i++)
    delete matrix1[i];
  delete matrix1;
  for (int i = 0; i < second_matrix_rows; i++)
    delete matrix2[i];
  delete matrix2;


  return 0;
}

string displayVector(vector<vector<float> > vec) {
  string res = "[";
  for (int i = 0; i < vec.size(); i++) {
    for (int j = 0; j < vec[0].size(); j++) {
      res += toString(vec[i][j]) + " ;"[j == vec[0].size() - 1];
    }
  }
  res[res.size() - 1] = ']'; 
  return res;
}

string display(float **matrix, int rows, int cols) {
  string res = "[";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      res += toString(matrix[i][j]) + " ;"[j == cols - 1];
    }
  }
  res[res.size() - 1] = ']'; 
  return res;
  
}

float** add(float **matrix1, float **matrix2, int rows, int cols) {

  float **matrix3 = new float*[rows];
  for (int i = 0; i < rows; i++)
    matrix3[i] = new float[cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  return matrix3;
}

float** subtract(float **matrix1, float **matrix2, int rows, int cols) {

  float **matrix3 = new float*[rows];
  for (int i = 0; i < rows; i++)
    matrix3[i] = new float[cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  return matrix3;  
}

float** multiply(float **matrix1, float **matrix2, 
    int rows1, int cols1, int rows2, int cols2) {

  float** matrix3 = new float*[rows1];
  for (int i = 0; i < rows1; i++) {
    matrix3[i] = new float[cols2];
    for (int j = 0; j < cols2; j++)
      matrix3[i][j] = 0;
  }

  for (int i = 0; i < rows1; i++)
    for (int j = 0; j < cols2; j++)
      for (int k = 0; k < cols1; k++)
        matrix3[i][j] += matrix1[i][k] * matrix2[k][j];

  return matrix3;
}

float** power(float **matrix, int rows, int cols, int p) {

  float **matrix2 = new float*[rows];
  for (int i = 0; i < rows; i++) {
    matrix2[i] = new float[cols];
    for (int j = 0; j < cols; j++)
      matrix2[i][j] = matrix[i][j];
  }

  for (int turns = 1; turns < p; turns++) {
    matrix2 = multiply(matrix, matrix2, rows, cols, rows, cols);
  }
  return matrix2;
}
  

void transpose(vector<vector<float> > mat) {
  
  vector<vector<float> > res(mat[0].size());
  for(int i = 0; i < res.size(); i++)
      res[i].resize(mat.size());
  
  for(int i = 0; i < mat.size(); i++)
    for(int j = 0; j < mat[0].size(); j++)
      res[j][i] = mat[i][j];

  string res2 = "[";
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[0].size(); j++) {
      res2 += toString(res[i][j]) + " ;"[j == res[0].size() - 1];
    }
  }
  res2[res2.size() - 1] = ']'; 
  cout << res2 << endl;
}

int powOfMinusOne(int exponent) {
  return exponent & 1 ? -1 : 1;
}

float determinant(int n, float **mat) {
  float **submat;
  float d = 0;
  int subi, subj;

  if (n == 1)
    return mat[0][0];
  else {
    for(int c = 0; c < n; c++) { 
      submat = new float*[n - 1];
      for (int i = 0; i < n - 1; i++) {
        submat[i] = new float[n - 1];
      }
      subi = 0;   //submatrix's i value
      for(int i = 1; i < n; i++) {
        subj = 0;
        for(int j = 0; j < n; j++) {
          if(j == c)
          continue;
          submat[subi][subj]=mat[i][j];
          subj++;
        }
        subi++;
      }
       // d = d + (pow(-1, c) * mat[0][c] * determinant(n-1 ,submat));
        d = d + (powOfMinusOne(c) * mat[0][c] * determinant(n-1 ,submat));
    }
  }
  return d;
}


vector<vector<float> > inverse(vector<vector<float> >Mat1 , int n) {

  vector<vector<float> >res;
  res.resize(n);
  int i, j, k;
  float a[101][101]={0}, d;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      a[i][j]=Mat1[i-1][j-1];
    }
  }    

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= 2 * n; j++) {
      if (j == (i + n)) {
        a[i][j] = 1;
      }
    }
  }
  
  for (i = n; i > 1; i--) {
    if (a[i-1][1] < a[i][1]) {
      for(j = 1; j <= n * 2; j++) {
        d = a[i][j];
        a[i][j] = a[i-1][j];
        a[i-1][j] = d;
      }
    }
  }
  
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n * 2; j++) {
      if (j != i) {
        d = a[j][i] / a[i][i];
        for (k = 1; k <= n * 2; k++) {
          a[j][k] = a[j][k] - (a[i][k] * d);
        } 
      }
    }
  }
  
  for (i = 1; i <= n; i++) {
    d=a[i][i];
    for (j = 1; j <= n * 2; j++) {
      a[i][j] = a[i][j] / d;
    }
  }
  
  for (i = 1; i <= n; i++) {
    for (j = n + 1; j <= n * 2; j++) {
      res[i-1].push_back(a[i][j]);
    }
  }
  return res;
}


float** divide(float **matrix1, float **matrix2,
    int rows1, int cols1, int rows2, int cols2) {  
  
  float **res = new float*[rows1];
  for (int i = 0; i < rows1; i++) {
    res[i] = new float[cols2];
    for (int j = 0; j < cols2; j++)
      res[i][j] = 0;
  }

  vector<vector<float> > tobe(rows2);
  for (int i = 0; i < rows2; i++) {
    tobe[i].resize(cols2);
    for (int j = 0; j < cols2; j++)
      tobe[i][j] = matrix2[i][j];
  }

  tobe = inverse(tobe, tobe.size());

  for (int i = 0; i < rows2; i++)
    for (int j = 0; j < cols2; j++)
      matrix2[i][j] = tobe[i][j];

  res = multiply(matrix1, matrix2, rows1, cols1, rows2, cols2);

  return res;
}

