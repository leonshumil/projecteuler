#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int main() {

  int matrix[101][52] = {0};

  ifstream f("q12_input.txt");
  if (!f.is_open()) {
        cerr << "Error opening file!"<< endl;
        return 1;
    }

 string line;
 int row = 0;
 while (getline(f, line) && row < 100) {
        for (int col = 0; col < 50; ++col) {
            matrix[row][col + 2] = line[col] - '0';
        }
        row++;
    }
 f.close();
 cout << "Matrix initialized and loaded successfully." << endl;

 int temp = 0;

 for (int col = 51; col >= 0; --col){
    for (int row = 0; row < 100; ++row){
       temp += matrix[row][col];
    }
    matrix[100][col] = temp%10;
    temp = temp/10 ; 
 }
 cout << "The result is: ";
for (int i = 0; i < 10; ++i) {
    cout << matrix[100][i];
}
cout << endl;

 return 0;
}