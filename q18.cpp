//Maximum Path Sum I
// insted of visinig all 16384 path and visiting it in q67 we'll find the optimal answer now. 
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (){

 int matrix[15][15] = {0};
 ifstream f("q18_input.txt");

  if (!f.is_open()) {
        cerr << "Error opening file!"<< endl;
        return 1;
    }

    for (int row = 0; row < 15; ++row) {
    for (int col = 0; col <= row; ++col) {
      f >> matrix[row][col];
    }
  }
  f.close();
  cout << "Matrix initialized and loaded successfully." << endl;
  for (int row = 13; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            matrix[row][col] += max(matrix[row + 1][col], matrix[row + 1][col + 1]);
        }
    }
    cout << "The maximum path sum is: " << matrix[0][0] << endl;
}